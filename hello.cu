// #include <print>
#include <cstdio>

__global__ void myKernel(void){
    int tid = threadIdx.x;
    // std::println("Hello World from thread {}", tid);
    printf("Hello World from thread %d\n", tid);
}

int main (){
    myKernel<<<1,5>>>(); // 1 block, 5 threads (Ids 0-4)
    cudaDeviceSynchronize();
    return 0; 
}
