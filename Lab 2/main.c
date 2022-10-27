#include <stdlib.h>
#include <stdio.h>

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2; //better than (l + r) / 2 in preventing overflows
        
        //recursively call mergeSort
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        //to merge both the results
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2]; //divide into two two subarrays

        for(int i = 0; i < n1; i++)
        {
            L[i] = arr[l + i];
        }
        for(int i = 0; i < n2; i++)
        {
            R[i] = arr[m + 1 + i];
        }
        int i = 0;
        int j = 0;
        int k = l;
        while(i < n1 && j < n2)
        {
            if(L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        //copy any remaining elements
        while(i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }

    }

}


//utility functions for quicksort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            //swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int index = partition(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }

}


int main()
{
    int arr1[] = {2, 15, 3, 25, 1, 2};
    mergeSort(arr1, 0, (sizeof(arr1) / sizeof(int)) - 1);
    for(int i = 0; i < sizeof(arr1) / sizeof(int); i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int arr2[] = {2, 32, 0, 25, 1, 1};
    quickSort(arr2, 0, ((sizeof(arr2) / sizeof(int)) - 1));
    for(int i = 0; i < sizeof(arr2) / sizeof(int); i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}