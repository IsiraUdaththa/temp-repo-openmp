#include <omp.h>

#include <numeric>
#include <print>
#include <vector>

#define N 1001

int main() {
    #pragma omp parallel
    {
        std::println("Thread {} is working", omp_get_thread_num());

        #pragma omp master
        {
            std::println("This is only executed by master thread {}", omp_get_thread_num());
        }


        std::println("Thread {} continues", omp_get_thread_num());
    }
    return 0;
}
