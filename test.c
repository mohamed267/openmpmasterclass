#include <stdio.h>
#include <omp.h>
void main ()
{
omp_set_num_threads(3);
#pragma omp parallel
{
int ID = omp_get_thread_num ();
printf("Hello(%d)\n", ID);
printf("world(%d)\n", ID);
}

printf("done our here");
}