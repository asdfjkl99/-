#include <stdio.h>
#include <stdlib.h>

void Swap(int* x1, int* x2)
{
    int* temp;
    temp = x1;
    x1 = x2;
    x2 = temp;
}

int Partition(int a[], int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i<end; i++)
    {
        if(a[i] < pivot)
        {
            Swap(&a[i], &a[pIndex]);
            ++pIndex;
        }
    }

    Swap(&a[pIndex], &a[end]);
    return pIndex;
}

void BubbleSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                Swap(&a[j], &a[j+1]);
            }
        }
    }
}

void SelectionSort(int a[], int n)
{
    int minIdx = 0;

    for(int i = 0; i<n-1 ; i++)
    {
        minIdx = i;
        for(int j = i+1; j<n; j++)
        {
            if(a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }

        if(minIdx != i)
        {
            Swap(&a[minIdx], &a[i]);
        }
    }
}

void InsertionSort(int a[], int n)
{
    for(int i = 1; i < n ; i++)
    {
        int j = i;
        while(j>0 && a[j-1] > a[j])
        {
            Swap(&a[j-1], &a[j]);
            --j;
        }
    }
}

void QuickSort(int a[], int start, int end) // for recursion
{
    if(start >= end)
        return;
    else
    {
        int pIndex = Partition(a, start, end);
        QuickSort(a, start, pIndex - 1);
        QuickSort(a, pIndex + 1, end);
    }
}