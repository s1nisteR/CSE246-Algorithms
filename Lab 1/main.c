//NOTE: Interestingly, Bubble Sort performs better on reverse sorted data than on random data as seen by the output times. 
//This is not expected normally, but is occurring due to branch prediction features of modern CPUs.
//Reference: https://stackoverflow.com/questions/20183549/why-does-my-bubble-sort-sort-reversed-data-far-faster-than-random-data-or-data-w
//By predicting the outcome of this comparison in advance, your processor can use its pipeline to process more iterations of the loop simultaneously, and finishes sorting earlier than it would have done with randomly ordered data.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>


//Bubble sort implementation
void bubbleSort(int arr[], int n)
{
    int i = n;
    bool sorted = false;
    while(i > 1 && !sorted)
    {
        sorted = true;
        for(int j = 0; j < i; j++)
        {
            if(arr[j - 1] > arr[j])
            {
                int temp = arr[j - 1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                sorted = false;
            }
        }
        i--;
    }
}

//Selection sort implementation
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        if(min_idx!=i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }

    }
}

//Insertion sort implementation
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main()
{
    double time_taken;
    clock_t start, end;
    FILE* sorted;
    FILE* reverse;
    FILE* random;

    int input;
    printf("1. 10k Data Set\n2. 20k Data Set\n3. 30k Data Set\n4. 40k Data Set\n5. 50k Data Set\nChoice: ");
    scanf("%d", &input);

    printf("\n");

    switch(input)
    {
        case 1:
        {
            sorted = fopen("10k_sorted.txt", "r");
            reverse = fopen("10k_reverse.txt", "r");
            random = fopen("10k_random.txt", "r");
            printf("Input Data Size: 10k\n");
            break;
        }
        case 2:
        {
            sorted = fopen("20k_sorted.txt", "r");
            reverse = fopen("20k_reverse.txt", "r");
            random = fopen("20k_random.txt", "r");
            printf("Input Data Size: 20k\n");
            break;
        }
        case 3:
        {
            sorted = fopen("30k_sorted.txt", "r");
            reverse = fopen("30k_reverse.txt", "r");
            random = fopen("30k_random.txt", "r");
            printf("Input Data Size: 30k\n");
            break;
        }
        case 4:
        {
            sorted = fopen("40k_sorted.txt", "r");
            reverse = fopen("40k_reverse.txt", "r");
            random = fopen("40k_random.txt", "r");
            printf("Input Data Size: 40k\n");
            break;
        }
        case 5:
        {
            sorted = fopen("50k_sorted.txt", "r");
            reverse = fopen("50k_reverse.txt", "r");
            random = fopen("50k_random.txt", "r");
            printf("Input Data Size: 50k\n");
            break;
        }
        default:
            printf("Invalid Option\n");
            exit(0);

    }

    //Error handling to ensure the files were loaded
    if(sorted == NULL || reverse == NULL || random == NULL)
    {
        printf("Could not find one or more of the files\n");
        exit(0);
    }
    

    input = (input * 10000) + 1; //because the input size is used later on to size the arrays and pass as sizes to the sort functions
    // +1 since numbers for example go from 0(inclusive) to 20k(inclusive) and so on 

    int sortedArr[input]; //sorted, best case
    int reverseArr[input]; //reverse, worst case
    int randomArr[input]; //random, average case


    //Read the files in
    for(int i = 0; i < input; i++)
    {
        fscanf(sorted, "%d", &sortedArr[i]);
    }
    for(int i = 0; i < input; i++)
    {
        fscanf(reverse, "%d", &reverseArr[i]);
    }
    for(int i = 0; i < input; i++)
    {
        fscanf(random, "%d", &randomArr[i]);
    }


    //===============FOR ALREADY SORTED DATA==============
    int tempSortedArr1[input];
    int tempSortedArr2[input];
    int tempSortedArr3[input];
    for(int i = 0; i < sizeof(sortedArr) / sizeof(int); ++i)
    {
        tempSortedArr1[i] = sortedArr[i];
        tempSortedArr2[i] = sortedArr[i];
        tempSortedArr3[i] = sortedArr[i];
    }

    start = clock();
    bubbleSort(tempSortedArr1, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort on Sorted Data: %lf\n", time_taken);

    start = clock();
    selectionSort(tempSortedArr2, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort on Sorted Data: %lf\n", time_taken);

    start = clock();
    insertionSort(tempSortedArr3, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort on Sorted Data: %lf\n", time_taken);
    //=========================================================

    printf("\n");


    //=============FOR REVERSED DATA=============================
    int tempReverseArr1[input];
    int tempReverseArr2[input];
    int tempReverseArr3[input];
    for(int i = 0; i < sizeof(reverseArr) / sizeof(int); ++i)
    {
        tempReverseArr1[i] = reverseArr[i];
        tempReverseArr2[i] = reverseArr[i];
        tempReverseArr3[i] = reverseArr[i];
    }

    start = clock();
    bubbleSort(tempReverseArr1, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort on Reverse Data: %lf\n", time_taken);

    start = clock();
    selectionSort(tempReverseArr2, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort on Reverse Data: %lf\n", time_taken);

    start = clock();
    insertionSort(tempReverseArr3, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort on Reverse Data: %lf\n", time_taken);
    //========================================================

    printf("\n");

    //===============FOR RANDOM DATA============================
    int tempRandomArr1[input];
    int tempRandomArr2[input];
    int tempRandomArr3[input];
    for(int i = 0; i < sizeof(randomArr) / sizeof(int); ++i)
    {
        tempRandomArr1[i] = randomArr[i];
        tempRandomArr2[i] = randomArr[i];
        tempRandomArr3[i] = randomArr[i];
    }

    start = clock();
    bubbleSort(tempRandomArr1, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort on Random Data: %lf\n", time_taken);

    start = clock();
    selectionSort(tempRandomArr2, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort on Random Data: %lf\n", time_taken);

    start = clock();
    insertionSort(tempRandomArr3, input);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort on Random Data: %lf\n", time_taken);
    //==========================================================
    return 0;
}
