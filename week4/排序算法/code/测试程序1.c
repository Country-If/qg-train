#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include "function.c"

#define LEN1 10000
#define LEN2 50000
#define LEN3 200000
#define RANGE 1000 //随机数范围

int main(void)
{
    int i, max;
    int test1[LEN1], test2[LEN2], test3[LEN3];
    int *temp;
    clock_t start, end;
    //生成大数据
    for(i = 0; i < LEN1; i++) //生成10000个随机数
    {
        test1[i] = rand() % RANGE; //生成0~999的数据(range - 1)
    }
    for(i = 0; i < LEN2; i++) //生成50000个随机数
    {
        test2[i] = rand() % RANGE; //生成0~999的数据
    }
    for(i = 0; i < LEN3; i++) //生成200000个随机数
    {
        test3[i] = rand() % RANGE; //生成0~999的数据
    }

    //测试排序
    printf("快排会压栈，测试快排请注释掉其他排序\n");
    printf("下面是%d个数据的排序情况：\n", LEN1);
    //插入排序
    start = clock();
    insertSort(test1, LEN1);
    end = clock();
    printf("插入排序：%d ms\n", end - start);
    //归并排序
    temp = (int *)malloc(sizeof(int) * LEN1);
    if(temp == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test1, 0, LEN1 - 1, temp);
    end = clock();
    printf("归并排序：%d ms\n", end - start);
    free(temp);
    //快速排序(递归)
    start = clock();
    QuickSort_Recursion(test1, 0, LEN1 - 1);
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);
    //快速排序(枢轴存放)
    start = clock();
    PartitionQuickSort(test1, 0, LEN1 - 1);
    end = clock();
    printf("快速排序(枢轴存放)：%d ms\n", end - start);
    //计数排序
    start = clock();
    max = arrayMax(test1, LEN1);
    CountSort(test1, LEN1, max);
    end = clock();
    printf("计数排序：%d ms\n", end - start);
    //基数排序
    start = clock();
    RadixCountSort(test1, LEN1);
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    printf("下面是%d个数据的排序情况：\n", LEN2);
    //插入排序
    start = clock();
    insertSort(test2, LEN2);
    end = clock();
    printf("插入排序：%d ms\n", end - start);
    //归并排序
    temp = (int *)malloc(sizeof(int) * LEN2);
    if(temp == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test2, 0, LEN2 - 1, temp);
    end = clock();
    printf("归并排序：%d ms\n", end - start);
    free(temp);
    //快速排序(递归)
    start = clock();
    QuickSort_Recursion(test2, 0, LEN2 - 1);
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);
    //快速排序(枢轴存放)
    start = clock();
    PartitionQuickSort(test2, 0, LEN2 - 1);
    end = clock();
    printf("快速排序(枢轴存放)：%d ms\n", end - start);
    //计数排序
    start = clock();
    max = arrayMax(test2, LEN2);
    CountSort(test2, LEN2, max);
    end = clock();
    printf("计数排序：%d ms\n", end - start);
    //基数排序
    start = clock();
    RadixCountSort(test2, LEN2);
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    printf("下面是%d个数据的排序情况：\n", LEN3);
    //插入排序
    start = clock();
    insertSort(test3, LEN3);
    end = clock();
    printf("插入排序：%d ms\n", end - start);
    //归并排序
    temp = (int *)malloc(sizeof(int) * LEN3);
    if(temp == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test3, 0, LEN3 - 1, temp);
    end = clock();
    printf("归并排序：%d ms\n", end - start);
    free(temp);
    //快速排序(递归)
    start = clock();
    QuickSort_Recursion(test3, 0, LEN3 - 1);
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);
    //快速排序(枢轴存放)
    start = clock();
    PartitionQuickSort(test3, 0, LEN3 - 1);
    end = clock();
    printf("快速排序(枢轴存放)：%d ms\n", end - start);
    //计数排序
    start = clock();
    max = arrayMax(test3, LEN3);
    CountSort(test3, LEN3, max);
    end = clock();
    printf("计数排序：%d ms\n", end - start);
    //基数排序
    start = clock();
    RadixCountSort(test3, LEN3);
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    system("pause");
    return 0;
}