#include <omp.h>
#include <stdio.h>
#include <pthread.h>

void main()
{
    int N = 100000;
    int A[N];
    for (int i = 0; i < N; i++)
        A[i] = i + 1;
    int S = 2;

    double itime, ftime, exec_time;
    itime = omp_get_wtime();
    for (int i = 0; i < N; i++)
    {
        A[i] += S;
    }

    ftime = omp_get_wtime();
    exec_time = ftime - itime;

    printf("\nTime taken is %f\n", exec_time);
    printf("\n");
}