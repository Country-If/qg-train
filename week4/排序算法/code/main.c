#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include "head.h"

//main函数
int main(void)
{
    int len, max, i; //数组长度，数组最大值，计数器
    int *data; //存入原始数据
    int *arr1, *arr2, *arr3, *arr4, *arr5, *arr6; //进行各种排序的数组
    int *temp = NULL;

    printf("没有写防脸滚键盘的功能，测试的时候请按要求输入！\n");
    //录入数据
    printf("请输入数组长度：");
    scanf("%d", &len);
    data = (int *)malloc(sizeof(int) * len);
    if(data == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    printf("请录入整型数据(以回车间隔)：\n");
    for(i = 0; i < len; i++)
    {
        scanf("%d", data + i);
    }
    printf("数据录入完毕\n录入的数据为：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(data + i));
    }
    printf("\n");

    //进行插入排序
    arr1 = (int *)malloc(sizeof(int) * len);
    if(arr1 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    memcpy(arr1, data, sizeof(int) * len);
    insertSort(arr1, len);
    printf("插入排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr1 + i));
    }
    printf("\n");

    //进行归并排序
    arr2 = (int *)malloc(sizeof(int) * len);
    if(arr2 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    temp = (int *)malloc(sizeof(int) * len);
    if(temp == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    memcpy(arr2, data, sizeof(int) * len);
    MergeSort(arr2, 0, len - 1, temp);
    printf("归并排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr2 + i));
    }
    free(temp);
    printf("\n");

    //进行快速排序(递归)
    arr3 = (int *)malloc(sizeof(int) * len);
    if(arr3 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    memcpy(arr3, data, sizeof(int) * len);
    QuickSort_Recursion(arr3, 0, len - 1);
    printf("快速排序(递归)后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr3 + i));
    }
    printf("\n");

    //进行快速排序(三数取中作为枢轴)
    arr4 = (int *)malloc(sizeof(int) * len);
    if(arr4 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    memcpy(arr4, data, sizeof(int) * len);
    PartitionQuickSort(arr4, 0, len - 1);
    printf("快速排序(三数取中作为枢轴)后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr4 + i));
    }
    printf("\n");

    //进行计数排序
    arr5 = (int *)malloc(sizeof(int) * len);
    if(arr5 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    memcpy(arr5, data, sizeof(int) * len);
    //找到数组中的最大值
    max = arr5[0];
    for(i = 0; i < len; i++)
    {
        if(arr5[i] > max)
        {
            max = arr5[i];
        }
    }
    CountSort(arr5, len, max);
    printf("计数排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr5 + i));
    }
    printf("\n");

    //进行基数计数排序
    arr6 = (int *)malloc(sizeof(int) * len);
    if(arr6 == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    memcpy(arr6, data, sizeof(int) * len);
    RadixCountSort(arr6, len);
    printf("基数计数排序后结果：\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr6 + i));
    }
    printf("\n");

    //释放内存
    free(data);
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    free(arr6);

    system("pause");
    return 0;
}
