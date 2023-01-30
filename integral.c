#include <stdio.h>
#include<omp.h>
#define NUM_THREADS 6
static long num_steps = 100000000;
double step = 0.0;
int main ()
{
   int nthreads , i ;
    double sum[NUM_THREADS] , pi=0.0, x=0.0 , start = 0.0;
    step = 1.0 / num_steps;

    start =  omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int i ,id , nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(id==0) nthreads = nthrds;

        for(i=id; i<num_steps ; i+=nthrds){
            x = i* step;
            sum[id] += 4/(1+x*x);
        }
        

    }

    for(i==0 ;i< nthreads ; i++){
        pi+= sum[i] * step;
    }
    printf("time is :  %f \n "  , omp_get_wtime() -start);
    
    printf("integrall is :  %f \n " ,pi);

}