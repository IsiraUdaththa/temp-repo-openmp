#include <print>
#include <omp.h>

// int main(){
//     int i = 100;

//     // #pragma omp parallel private(i)
//     // #pragma omp parallel firstprivate(i)
//     // #pragma omp parallel lastprivate(i)
//     #pragma omp parallel threadprivate(i)
//     {
//         auto thread_num = omp_get_thread_num();
//         i = i + thread_num;
//         std::println("id: {} : private value : {}", thread_num, i);
//     }

//     #pragma omp parallel threadprivate(i)
//     {
//         auto thread_num = omp_get_thread_num();
//         i = i + thread_num;
//         std::println("id: {} : private value : {}", thread_num, i);
//     }

//     std::println("{}", omp_get_)

//     if((omp_get_thread_num()==0))
//     {
//         std::println("Final counter value : {}", i);
//     }
    
//     return 0;
// }

#include <print>
#include <omp.h>

int main() {
    int i = 100;

    // Correct: combined 'parallel for' allows lastprivate
    #pragma omp parallel for lastprivate(i)
    for (int n = 0; n < 4; n++) {
        i = n + 10; // Each thread does some work
        std::println("Thread {} processed loop {} {}", omp_get_thread_num(), n, i);
    }

    // 'i' will take the value from the sequentially last iteration (n = 3)
    std::println("Final i value: {}", i); // Prints 13

    return 0;
}