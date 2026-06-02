#include <print>
#include <vector>
#include <chrono>
#include <omp.h>

// 10,000 x 10,000 matrix = 100 million elements (~400 MB per matrix)
constexpr int ROWS = 10000;
constexpr int COLS = 10000;
constexpr size_t TOTAL_SIZE = static_cast<size_t>(ROWS) * COLS;

int main() {
    // Check if a GPU/Accelerator is actually available
    int num_devices = omp_get_num_devices();
    std::println("Number of available target devices: {}", num_devices);
    if (num_devices == 0) {
        std::println("Warning: No GPU found. Code will fallback to CPU execution.");
    }

    // Flattening 2D matrices into 1D vectors for continuous memory (essential for GPU)
    std::vector<float> A(TOTAL_SIZE, 1.0f); // Filled with 1.0
    std::vector<float> B(TOTAL_SIZE, 2.0f); // Filled with 2.0
    std::vector<float> C(TOTAL_SIZE, 0.0f); // Result matrix

    // Get raw pointers for OpenMP target data mapping
    float* pA = A.data();
    float* pB = B.data();
    float* pC = C.data();

    auto start = std::chrono::high_resolution_clock::now();

    // OpenMP GPU Offloading Directive
    // map(to: ...) sends data to GPU. map(from: ...) brings data back from GPU.
    #pragma omp target data map(to: pA[0:TOTAL_SIZE], pB[0:TOTAL_SIZE]) map(from: pC[0:TOTAL_SIZE])
    {
        // 'teams distribute parallel for' breaks the loop into blocks and distributes them across GPU compute units
        #pragma omp target teams distribute parallel for collapse(2)
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                size_t idx = static_cast<size_t>(r) * COLS + c;
                pC[idx] = pA[idx] + pB[idx];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    // Verify the results
    std::println("Matrix addition completed in: {:.2f} ms", duration.count());
    std::println("Verification: C[0] = {} (Expected: 3.0)", C[0]);
    std::println("Verification: C[last] = {} (Expected: 3.0)", C[TOTAL_SIZE - 1]);

    return 0;
}