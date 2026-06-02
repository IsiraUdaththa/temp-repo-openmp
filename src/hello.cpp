#include <iostream>
#include <omp.h> // Include the OpenMP header

int main() {
    // This directive tells GCC to parallelize the block below
    #pragma omp parallel
    {
        auto thread_id            = omp_get_thread_num();
        auto thread_limit        = omp_get_thread_limit();
        auto max_threads         = omp_get_max_threads();
        auto num_threads         = omp_get_num_threads();
        auto teams_thread_limit  = omp_get_teams_thread_limit();
        // auto ancestor_thread_num = omp_get_ancestor_thread_num();



        // std::cout << "thread_id : " << thread_id << "\n";
        std::cout << "thread_id : " << thread_id << "\t" << "thread_limit : " << thread_limit << "\n";
        std::cout << "thread_id : " << thread_id << "\t" << "max_threads : " << max_threads << "\n";
        std::cout << "thread_id : " << thread_id << "\t" << "num_threads : " << num_threads << "\n";
        std::cout << "thread_id : " << thread_id << "\t" << "teams_thread_limit : " << teams_thread_limit << "\n";
        // std::cout << "ancestor_thread_num : " << ancestor_thread_num << "\n";

        // std::cout << "Hello from thread " << thread_id << "\n";
    }
    return 0;
}