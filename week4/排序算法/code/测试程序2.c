#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include "function.c"

#define N 100000 //ִ�д���
#define M 100 //ÿ������ĳ���
#define RANGE 1000 //�������Χ

int main(void)
{
    int data[M];
    int i, j, max;
    int *temp;
    clock_t start, end;
    
    //��������
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
    printf("��������%d ms\n", end - start);

    //�鲢����
    start = clock();
    for(i = 0; i < N; i++)
    {
        temp = (int *)malloc(sizeof(int) * M);
        if(temp == NULL)
        {
            printf("�ڴ����ʧ��\n");
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
    printf("�鲢����%d ms\n", end - start);

    //��������(�ݹ�)
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
    printf("��������(�ݹ�)��%d ms\n", end - start);

    //��������(������)
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
    printf("��������(������)��%d ms\n", end - start);

    //��������
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
    printf("��������%d ms\n", end - start);

    //��������
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
    printf("��������%d ms\n", end - start);

    system("pause");
    return 0;
}