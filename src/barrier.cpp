#include <print>
#include <omp.h>
#include <thread>      // For std::this_thread::sleep_for
#include <chrono>      // For std::chrono::seconds

int main(){
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();
     
        std::println("Thread {} starting phase 1", id);

        // sleep(id);
        std::this_thread::sleep_for(std::chrono::seconds(id));

        #pragma omp barrier

        std::println("");
        std::println("Thread {} starting phase 2", id);
    }
    
    return 0;
}