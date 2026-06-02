#include <omp.h>

#include <numeric>
#include <print>
#include <vector>

#define N 1001

int main() {
    std::vector<int> numbers(N);
    std::iota(numbers.begin(), numbers.end(), 0);

    for (int i = 0; i < N; i++) {
            std::println("{}", numbers[i]);
        }


    int sum = 0;

    // #pragma omp parallel shared(numbers) shared(sum)
    #pragma omp parallel shared(numbers, sum)
    {
        int local_sum = 0;

        #pragma omp for
        for (int i = 0; i < N; i++) {
            local_sum += numbers[i];
        }
        #pragma omp atomic
        sum+=local_sum;
    }

    std::println("Sum : {}", sum);
    return 0;
}
