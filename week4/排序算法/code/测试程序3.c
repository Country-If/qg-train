#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include "function.c"

#define RANGE 1000 //随机数范围
#define LEN1 10000
#define LEN2 50000
#define LEN3 200000
#define LEN 200000
#define BUFFER 10
#define N 100000 //执行次数
#define M 100 //每个数组的长度

int main(void)
{
    FILE *fp;
    int i, j, max;
    int *temp;
    int test[LEN], data[M];
    clock_t start, end;
    
    if((fp = fopen("data.txt", "w")) == NULL)
    {
        printf("文件打开失败\n");
        exit(1);
    }
    for(i = 0; i < LEN; i++)
    {
        fprintf(fp,"%d ", rand() % RANGE);
    }
    fclose(fp);

    if((fp = fopen("data.txt","r")) == NULL)
    {
        printf("文件打开失败\n");
        exit(1);
    }
    i = 0;
    while((fscanf(fp, "%d", &test[i])) != EOF)
    {
        i++;
    }
    fclose(fp);
    
    //大数据测试
    printf("下面测试不同大数据的排序情况\n");
    printf("下面是%d个数据的排序情况：\n", LEN1);
    //插入排序
    start = clock();
    insertSort(test, LEN1);
    end = clock();
    printf("插入排序：%d ms\n", end - start);
    //归并排序
    start = clock();
    temp = (int *)malloc(sizeof(int) * LEN1);
    if(temp == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test, 0, LEN1 - 1, temp);
    end = clock();
    free(temp);
    printf("归并排序：%d ms\n", end - start);
    //快速排序(递归)
    start = clock();
    QuickSort_Recursion(test, 0, LEN1 - 1);
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);
    //快速排序(枢轴存放)
    start = clock();
    PartitionQuickSort(test, 0, LEN1 - 1);
    end = clock();
    printf("快速排序(枢轴存放)：%d ms\n", end - start);
    //计数排序
    start = clock();
    max = arrayMax(test, LEN1);
    CountSort(test, LEN1, max);
    end = clock();
    printf("计数排序：%d ms\n", end - start);
    //基数排序
    start = clock();
    RadixCountSort(test, LEN1);
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    printf("下面是%d个数据的排序情况：\n", LEN2);
    //插入排序
    start = clock();
    insertSort(test, LEN2);
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
    MergeSort(test, 0, LEN2 - 1, temp);
    end = clock();
    printf("归并排序：%d ms\n", end - start);
    free(temp);
    //快速排序(递归)
    start = clock();
    QuickSort_Recursion(test, 0, LEN2 - 1);
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);
    //快速排序(枢轴存放)
    start = clock();
    PartitionQuickSort(test, 0, LEN2 - 1);
    end = clock();
    printf("快速排序(枢轴存放)：%d ms\n", end - start);
    //计数排序
    start = clock();
    max = arrayMax(test, LEN2);
    CountSort(test, LEN2, max);
    end = clock();
    printf("计数排序：%d ms\n", end - start);
    //基数排序
    start = clock();
    RadixCountSort(test, LEN2);
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    printf("下面是%d个数据的排序情况：\n", LEN3);
    //插入排序
    start = clock();
    insertSort(test, LEN3);
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
    MergeSort(test, 0, LEN3 - 1, temp);
    end = clock();
    printf("归并排序：%d ms\n", end - start);
    free(temp);
    //快速排序(递归)
    start = clock();
    QuickSort_Recursion(test, 0, LEN3 - 1);
    end = clock();
    printf("快速排序(递归)：%d ms\n", end - start);
    //快速排序(枢轴存放)
    start = clock();
    PartitionQuickSort(test, 0, LEN3 - 1);
    end = clock();
    printf("快速排序(枢轴存放)：%d ms\n", end - start);
    //计数排序
    start = clock();
    max = arrayMax(test, LEN3);
    CountSort(test, LEN3, max);
    end = clock();
    printf("计数排序：%d ms\n", end - start);
    //基数排序
    start = clock();
    RadixCountSort(test, LEN3);
    end = clock();
    printf("基数排序：%d ms\n", end - start);

    /* //测试大量小数组,这里写我的思路
    printf("\n下面测试大量小数组\n");
    start = clock();
    //进行100k次排序，每次对大小为100的数组进行排序
    for(i = 0; i < N; i++)
    {
        //生成大小为100的数据，写入txt
        if((fp = fopen("data.txt", "w")) == NULL)
        {
            printf("文件打开失败\n");
            exit(1);
        }
        for(j = 0; j < M; i++)
        {
            fprintf(fp,"%d ", rand() % RANGE);
        }
        fclose(fp);
        //读取txt数据，保存到数组
        if((fp = fopen("data.txt","r")) == NULL)
        {
            printf("文件打开失败\n");
            exit(1);
        }
        j = 0;
        while((fscanf(fp, "%d", &test[j])) != EOF)
        {
            j++;
        }
        fclose(fp);
        //调用排序的函数进行排序
        //function
    }
    end = clock();
    printf("排序：%d ms\n", end - start); */

    system("pause");
    return 0;
}