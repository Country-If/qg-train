#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include "head.h" 
#include "function.c"

int main(void)
{
    int len1, len2, i, k, kNum;
    int *data; //存放数据
    int *colorArray; //颜色排序数组

    printf("没有写防脸滚键盘的功能，测试的时候请按要求输入！\n");
    //录入数组长度
    printf("请输入数组长度：");
    scanf("%d", &len1);
    
    data = (int *)malloc(sizeof(int) * len1);
    if(data == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    printf("请录入整型数据(以回车间隔)：\n");
    for(i = 0; i < len1; i++)
    {
        scanf("%d", data + i);
    }
    printf("数据录入完毕\n录入的数据为：\n");
    for(i = 0; i < len1; i++)
    {
        printf("%d\t", *(data + i));
    }
    printf("\n");

    //找第K大的数
    printf("你想找第几大的数：");
    scanf("%d", &k);
    kNum = FindKNum(data, len1, k);
    if(kNum == -1)
    {
        printf("查找越界\n");
    }
    else
    {
        printf("第K大的数为：%d\n", kNum);
    }

    //录入数组长度
    printf("请输入数组长度：");
    scanf("%d", &len2);

    colorArray = (int *)malloc(sizeof(int) * len2);
    if(colorArray == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        return -1;
    }
    for(i = 0; i < len2; i++)
    {
        colorArray[i] = rand() % 3;
    }
    printf("颜色排序随机生成数组：\n");
    for(i = 0; i < len2; i++)
    {
        printf("%d\t", colorArray[i]);
    }
    printf("\n");

    //颜色排序
    ColorSort(colorArray, len2);
    printf("颜色排序后数组：\n");
    for(i = 0; i < len2; i++)
    {
        printf("%d\t", colorArray[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
