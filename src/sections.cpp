#include <print>
#include <omp.h>
#include <thread>      // For std::this_thread::sleep_for
#include <chrono>      // For std::chrono::seconds

int main(){

    const int size = 16;


    #pragma omp parallel 
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                std::println("Section 1 executed by thread {}", omp_get_thread_num());
            }
            
            #pragma omp section
            {
                std::println("Section 2 executed by thread {}", omp_get_thread_num());
            }

            #pragma omp section
            {
                std::println("Section 3 executed by thread {}", omp_get_thread_num());
            }

            #pragma omp section
            {
                std::println("Section 4 executed by thread {}", omp_get_thread_num());
            }
        }
    }

    return 0;
}