#include <stdio.h>
#include<omp.h>
#define NUM_THREADS 3
static long num_steps = 1000000000;
double step = 0.0;
int main ()
{
   int nthreads , i ;
    double  pi=0.0, x=0.0 , start = 0.0;
    step = 1.0 / num_steps;

    start =  omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int i ,id , nthrds;
        double sum = 0.0;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(id==0) nthreads = nthrds;
        #pragma omp for  reduction(+:sum)
            for(i=0; i<num_steps ; i+=1){
                x = i* step;
                sum += 4/(1+x*x);
            }

        
        #pragma omp critical 
            pi += sum * step;

    }

    printf("time is :  %f \n "  , omp_get_wtime() -start);
    
    printf("integrall is :  %f \n ", pi);

}