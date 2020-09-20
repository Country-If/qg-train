#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include "function.c"

#define N 100000 //执行次数
#define M 100 //每个数组的长度
#define RANGE 1000 //随机数范围

int main(void)
{
    int data[M];
    int i, j, max;
    int *temp;
    clock_t start, end;
    
    //插入排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            data[j] = rand() % RANGE;
        }
        insertSort(data, M);
    }
    end = clock();
    printf("插入排序：%d ms\n", end - start);

    //归并排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        temp = (int *)malloc(sizeof(int) * M);
        if(temp == NULL)
        {
            printf("内存分配失败\n");
            system("pause");
            exit(0);
        }
        for(j = 0; j < M; j++)
        {
            data[j] = rand() % RANGE;
        }
        MergeSort(data, 0, M - 1, temp);
        free(temp);
    }
    end = clock();
    printf("归并排序：%d ms\n", end - start);

    //快速排序(递归)
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            data[j] = rand() % RANGE;
        }
        QuickSort_Recursion(data, 0, M - 1);
    }
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);

    //快速排序(枢轴存放)
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            data[j] = rand() % RANGE;
        }
        PartitionQuickSort(data, 0, M - 1);
    }
    end = clock();
    printf("快速排序(枢轴存放)：%d ms\n", end - start);

    //计数排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            data[j] = rand() % RANGE;
        }
        max = arrayMax(data, M);
        CountSort(data, M, max);
    }
    end = clock();
    printf("计数排序：%d ms\n", end - start);

    //基数排序
    start = clock();
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            data[j] = rand() % RANGE;
        }
        RadixCountSort(data, M);
    }
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    system("pause");
    return 0;
}