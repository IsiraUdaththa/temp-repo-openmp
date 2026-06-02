// #include <print>
#include <cstdio>

__global__ void add(int *a, int *b, int *c){
    int idx = threadIdx.x;

    c[idx] = a[idx] + b[idx];
    // std::println("Hello World from thread {}", tid);
    // printf("Hello World from thread %d\n", idx);
}


int main(){
    int h_a[5] = {1,2,3,4,5};
    int h_b[5] = {10,20,30,40,50};
    int h_c[5];
    
    int *d_a, *d_b, *d_c;

    cudaMalloc(&d_a, 5*sizeof(int));
    cudaMalloc(&d_b, 5*sizeof(int));
    cudaMalloc(&d_c, 5*sizeof(int));

    cudaMemcpy(d_a, h_a, 5*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, 5*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, h_c, 5*sizeof(int), cudaMemcpyHostToDevice);
    
    add<<<1,5>>>(d_a, d_b, d_c);

    cudaMemcpy(h_c, d_c, 5*sizeof(int), cudaMemcpyDeviceToHost);

    for (int i=0; i<5; i++){
        printf("%d -> %d  \n", i, h_c[i]);
    }
    
    return 0;
}
