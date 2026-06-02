#include <print>
#include <omp.h>
#include <thread>      // For std::this_thread::sleep_for
#include <chrono>      // For std::chrono::seconds

int main(){

    const int size = 16;


    #pragma omp parallel for schedule(static, 3)
    for (int i=0; i < size; i++){
        std::println("Thread {} processes iteration {}", omp_get_thread_num(), i);
    }

    return 0;
}