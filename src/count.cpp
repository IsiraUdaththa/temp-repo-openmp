#include <print>
#include <omp.h>


int main(){
    int shared_counter = 0;

    #pragma omp parallel shared(shared_counter)
    {
        #pragma omp atomic
        shared_counter++;
        #pragma omp barrier
    }

    // if((omp_get_thread_num()==0))
    std::println("Final counter value : {}", shared_counter);

    
    return 0;
}