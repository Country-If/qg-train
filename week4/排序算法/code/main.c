#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include "head.h"

//main����
int main(void)
{
    int len, max, i; //���鳤�ȣ��������ֵ��������
    int *data; //����ԭʼ����
    int *arr1, *arr2, *arr3, *arr4, *arr5, *arr6; //���и������������
    int *temp = NULL;

    printf("û��д���������̵Ĺ��ܣ����Ե�ʱ���밴Ҫ�����룡\n");
    //¼������
    printf("���������鳤�ȣ�");
    scanf("%d", &len);
    data = (int *)malloc(sizeof(int) * len);
    if(data == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    printf("��¼����������(�Իس����)��\n");
    for(i = 0; i < len; i++)
    {
        scanf("%d", data + i);
    }
    printf("����¼�����\n¼�������Ϊ��\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(data + i));
    }
    printf("\n");

    //���в�������
    arr1 = (int *)malloc(sizeof(int) * len);
    if(arr1 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    memcpy(arr1, data, sizeof(int) * len);
    insertSort(arr1, len);
    printf("�������������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr1 + i));
    }
    printf("\n");

    //���й鲢����
    arr2 = (int *)malloc(sizeof(int) * len);
    if(arr2 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    temp = (int *)malloc(sizeof(int) * len);
    if(temp == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    memcpy(arr2, data, sizeof(int) * len);
    MergeSort(arr2, 0, len - 1, temp);
    printf("�鲢���������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr2 + i));
    }
    free(temp);
    printf("\n");

    //���п�������(�ݹ�)
    arr3 = (int *)malloc(sizeof(int) * len);
    if(arr3 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    memcpy(arr3, data, sizeof(int) * len);
    QuickSort_Recursion(arr3, 0, len - 1);
    printf("��������(�ݹ�)������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr3 + i));
    }
    printf("\n");

    //���п�������(����ȡ����Ϊ����)
    arr4 = (int *)malloc(sizeof(int) * len);
    if(arr4 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    memcpy(arr4, data, sizeof(int) * len);
    PartitionQuickSort(arr4, 0, len - 1);
    printf("��������(����ȡ����Ϊ����)������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr4 + i));
    }
    printf("\n");

    //���м�������
    arr5 = (int *)malloc(sizeof(int) * len);
    if(arr5 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    memcpy(arr5, data, sizeof(int) * len);
    //�ҵ������е����ֵ
    max = arr5[0];
    for(i = 0; i < len; i++)
    {
        if(arr5[i] > max)
        {
            max = arr5[i];
        }
    }
    CountSort(arr5, len, max);
    printf("�������������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr5 + i));
    }
    printf("\n");

    //���л�����������
    arr6 = (int *)malloc(sizeof(int) * len);
    if(arr6 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    memcpy(arr6, data, sizeof(int) * len);
    RadixCountSort(arr6, len);
    printf("�����������������\n");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", *(arr6 + i));
    }
    printf("\n");

    //�ͷ��ڴ�
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
