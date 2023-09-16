/*
Hugo Coto Florez
binary search implementation
big-O deduction
calculate execution time
educational purpose
*/

#include <stdio.h>
#include <time.h>
#include <math.h>


int find(int* arr, int elem, int len)
//using binary search: O(log2(n)), where n=len
{
    int start = 0;
    int stop = len-1;
    int mid;
    int i = 0; //use to calculate iterations
    clock_t t1 = clock(); //use to calculate the execution time
    //generic binary search algorithm
    while (start < stop)
    {
        mid = (start+stop)/2;

        if (elem > arr[mid])
        {
            start = mid+1;
        }
        else
        {
            stop = mid;
        }
        i++; //increment the iterations counter
    }

    long double t = (long double) (clock()-t1) / CLOCKS_PER_SEC;//exec time
    double e = log2(len); //estimation by its big-O 
    printf("%i iterations <- array[%i] (%Lfs) [log2(arr len): %f]\n", i, len, t, e);

    return (arr[start]==elem)? start : -1;
}

int main(void)
{
    //size of the array
    int size = 10000;
    //create an array (0,size]
    int arr[size];
    for(int i = 0; i<size; i++)
    {
        arr[i] = i;
    }
    //calculate the size
    int len = sizeof(arr) / sizeof(arr[0]);
    //get the index of the element in the array
    int index = find(arr, 234, len);  
    return 0;
}