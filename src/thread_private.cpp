#include <print>
#include <omp.h>


int thread_private_var;
#pragma omp threadprivate( thread_private_var)

int main(){
    int i = 10000;

    #pragma omp parallel firstprivate(i)
    #pragma omp parallel
    {
        auto thread_num = omp_get_thread_num();
        thread_private_var = i + thread_num;
        std::println("id: {} : private value : {}", thread_num, i);
    }

    // #pragma omp parallel threadprivate(i)
    // {
    //     auto thread_num = omp_get_thread_num();
    //     i = i + thread_num;
    //     std::println("id: {} : private value : {}", thread_num, i);
    // }


    if((omp_get_thread_num()==0))
    {
        std::println("i value : {}", i);
        std::println("thread value: {}", thread_private_var);
    }
    
    return 0;
}
