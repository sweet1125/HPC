#include <stdio.h>
#include <time.h>

#define n 100000
void sort(int arr[])
{
    int i, j, first;
    for (i = 0; i < n; i++)
    {
        first = i % 2;
#pragma omp parallel for
        for (j = first; j < n - 1; j += 2)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sort_des(int arr[])
{
    int i, j, first;
    for (i = 0; i < n; ++i)
    {
        first = i % 2;
#pragma omp parallel for
        for (j = first; j < n - 1; j += 2)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int arr1[n], arr2[n];
    int i;
    for (i = 0; i < n; i++)
    {

        arr1[i] = n - i;
    }
    for (i = 0; i < n; i++)
    {

        arr2[i] = i;
    }

    clock_t t;
    t = clock();

    sort(arr1);
    sort_des(arr2);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("Time taken (parallel): %f\n", time_taken);

    int sum = 0;
    for (i = 0; i < n; i++)
    {

        sum = sum + (arr1[i] * arr2[i]);
    }

    printf("%d\n", sum);
    return 0;
}