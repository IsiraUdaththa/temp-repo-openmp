#include <print>
#include <omp.h>

int main(){
    int sum = 0;

    #pragma omp parallel 
    {
        int local_sum = 0;
        for(int i =0; i < 1000; i++){
            local_sum++;
        }

        
        #pragma omp critical
        {
            sum += local_sum;
            std::println("Thread {} added its local sum \n", omp_get_thread_num());
        }
    }

    std::println("Final sum value : {}", sum);

    return 0;
}

