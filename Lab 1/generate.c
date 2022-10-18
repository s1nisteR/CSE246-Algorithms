#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include <time.h>



int main()
{
    //File handlers for sorted
    FILE* hFile;
    FILE* hFile2;
    FILE* hFile3;
    FILE* hFile4;
    FILE* hFile5;
    hFile = fopen("10k_sorted.txt", "w");
    hFile2 = fopen("20k_sorted.txt", "w");
    hFile3 = fopen("30k_sorted.txt", "w");
    hFile4 = fopen("40k_sorted.txt", "w");
    hFile5 = fopen("50k_sorted.txt", "w");

    
    //File handlers for reverse sorted data
    FILE* rev1;
    FILE* rev2;
    FILE* rev3;
    FILE* rev4;
    FILE* rev5;
    rev1 = fopen("10k_reverse.txt", "w");
    rev2 = fopen("20k_reverse.txt", "w");
    rev3 = fopen("30k_reverse.txt", "w");
    rev4 = fopen("40k_reverse.txt", "w");
    rev5 = fopen("50k_reverse.txt", "w");

    
    //File handlers for random data
    FILE* rnd;
    FILE* rnd2;
    FILE* rnd3;
    FILE* rnd4;
    FILE* rnd5;
    rnd = fopen("10k_random.txt", "w");
    rnd2 = fopen("20k_random.txt", "w");
    rnd3 = fopen("30k_random.txt", "w");
    rnd4 = fopen("40k_random.txt", "w");
    rnd5 = fopen("50k_random.txt", "w");

    //=================GENERATE SORTED DATA====================


    //Generate 10k numbers, 0 to 10,000 inclusive
    for(int i = 0; i <= 10000; i++)
    {
        fprintf(hFile, "%d", i);
        fprintf(hFile, " ");
    }
    fclose(hFile);

    //Generate 20k numbers, 0 to 20,000 inclusive
    for(int i = 0; i <= 20000; i++)
    {
        fprintf(hFile2, "%d", i);
        fprintf(hFile2, " ");
    }
    fclose(hFile2);

    //Generate 30k numbers, 0 to 30,000 inclusive
    for(int i = 0; i <= 30000; i++)
    {
        fprintf(hFile3, "%d", i);
        fprintf(hFile3, " ");
    }
    fclose(hFile3);

    //Generate 40k numbers, 0 to 40,000 inclusive
    for(int i = 0; i <= 40000; i++)
    {
        fprintf(hFile4, "%d", i);
        fprintf(hFile4, " ");
    }
    fclose(hFile4);

    //Generate 50k numbers, 0 to 50,000 inclusive
    for(int i = 0; i <= 50000; i++)
    {
        fprintf(hFile5, "%d", i);
        fprintf(hFile5, " ");
    }
    fclose(hFile5);


    //=============GENERATE REVERSE SORTED DATA======================
    
    //10k to 0 inclusive
    for(int i = 10000; i >= 0; i--)
    {
        fprintf(rev1, "%d", i);
        fprintf(rev1, " ");
    }
    fclose(rev1);

    //20k to 0 inclusive
    for(int i = 20000; i >= 0; i--)
    {
        fprintf(rev2, "%d", i);
        fprintf(rev2, " ");
    }
    fclose(rev2);

    //30k to 0 inclusive
    for(int i = 30000; i >= 0; i--)
    {
        fprintf(rev3, "%d", i);
        fprintf(rev3, " ");
    }
    fclose(rev3);

    //40k to 0 inclusive
    for(int i = 40000; i >= 0; i--)
    {
        fprintf(rev4, "%d", i);
        fprintf(rev4, " ");
    }
    fclose(rev4);

    //50k to 0 inclusive
    for(int i = 50000; i >= 0; i--)
    {
        fprintf(rev5, "%d", i);
        fprintf(rev5, " ");
    }
    fclose(rev5);


    //================GENERATE RANDOM DATA================
    time_t t;
    srand((unsigned int)time(&t));

    //For 10k random numbers
    for(int i = 0; i < 10000; ++i)
    {
        fprintf(rnd, "%d", rand() % INT_MAX);
        fprintf(rnd, " ");
    }
    fclose(rnd);


    //For 20k random numbers
    for(int i = 0; i < 20000; ++i)
    {
        fprintf(rnd2, "%d", rand() % INT_MAX);
        fprintf(rnd2, " ");
    }
    fclose(rnd2);

    //For 30k random numbers
    for(int i = 0; i < 30000; ++i)
    {
        fprintf(rnd3, "%d", rand() % INT_MAX);
        fprintf(rnd3, " ");
    }
    fclose(rnd3);

    //For 40k random numbers
    for(int i = 0; i < 40000; ++i)
    {
        fprintf(rnd4, "%d", rand() % INT_MAX);
        fprintf(rnd4, " ");
    }
    fclose(rnd4);

    //For 50k random numbers
    for(int i = 0; i < 50000; ++i)
    {
        fprintf(rnd5, "%d", rand() % INT_MAX);
        fprintf(rnd5, " ");
    }
    fclose(rnd5);

    return 0;
}