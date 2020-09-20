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
#define RANGE 1000 //�������Χ

int main(void)
{
    int i, max;
    int test1[LEN1], test2[LEN2], test3[LEN3];
    int *temp;
    clock_t start, end;
    //���ɴ�����
    for(i = 0; i < LEN1; i++) //����10000�������
    {
        test1[i] = rand() % RANGE; //����0~999������(range - 1)
    }
    for(i = 0; i < LEN2; i++) //����50000�������
    {
        test2[i] = rand() % RANGE; //����0~999������
    }
    for(i = 0; i < LEN3; i++) //����200000�������
    {
        test3[i] = rand() % RANGE; //����0~999������
    }

    //��������
    printf("���Ż�ѹջ�����Կ�����ע�͵���������\n");
    printf("������%d�����ݵ����������\n", LEN1);
    //��������
    start = clock();
    insertSort(test1, LEN1);
    end = clock();
    printf("��������%d ms\n", end - start);
    //�鲢����
    temp = (int *)malloc(sizeof(int) * LEN1);
    if(temp == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test1, 0, LEN1 - 1, temp);
    end = clock();
    printf("�鲢����%d ms\n", end - start);
    free(temp);
    //��������(�ݹ�)
    start = clock();
    QuickSort_Recursion(test1, 0, LEN1 - 1);
    end = clock();
    printf("��������(�ݹ�)��%d ms\n", end - start);
    //��������(������)
    start = clock();
    PartitionQuickSort(test1, 0, LEN1 - 1);
    end = clock();
    printf("��������(������)��%d ms\n", end - start);
    //��������
    start = clock();
    max = arrayMax(test1, LEN1);
    CountSort(test1, LEN1, max);
    end = clock();
    printf("��������%d ms\n", end - start);
    //��������
    start = clock();
    RadixCountSort(test1, LEN1);
    end = clock();
    printf("��������%d ms\n", end - start);

    printf("������%d�����ݵ����������\n", LEN2);
    //��������
    start = clock();
    insertSort(test2, LEN2);
    end = clock();
    printf("��������%d ms\n", end - start);
    //�鲢����
    temp = (int *)malloc(sizeof(int) * LEN2);
    if(temp == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test2, 0, LEN2 - 1, temp);
    end = clock();
    printf("�鲢����%d ms\n", end - start);
    free(temp);
    //��������(�ݹ�)
    start = clock();
    QuickSort_Recursion(test2, 0, LEN2 - 1);
    end = clock();
    printf("��������(�ݹ�)��%d ms\n", end - start);
    //��������(������)
    start = clock();
    PartitionQuickSort(test2, 0, LEN2 - 1);
    end = clock();
    printf("��������(������)��%d ms\n", end - start);
    //��������
    start = clock();
    max = arrayMax(test2, LEN2);
    CountSort(test2, LEN2, max);
    end = clock();
    printf("��������%d ms\n", end - start);
    //��������
    start = clock();
    RadixCountSort(test2, LEN2);
    end = clock();
    printf("��������%d ms\n", end - start);

    printf("������%d�����ݵ����������\n", LEN3);
    //��������
    start = clock();
    insertSort(test3, LEN3);
    end = clock();
    printf("��������%d ms\n", end - start);
    //�鲢����
    temp = (int *)malloc(sizeof(int) * LEN3);
    if(temp == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test3, 0, LEN3 - 1, temp);
    end = clock();
    printf("�鲢����%d ms\n", end - start);
    free(temp);
    //��������(�ݹ�)
    start = clock();
    QuickSort_Recursion(test3, 0, LEN3 - 1);
    end = clock();
    printf("��������(�ݹ�)��%d ms\n", end - start);
    //��������(������)
    start = clock();
    PartitionQuickSort(test3, 0, LEN3 - 1);
    end = clock();
    printf("��������(������)��%d ms\n", end - start);
    //��������
    start = clock();
    max = arrayMax(test3, LEN3);
    CountSort(test3, LEN3, max);
    end = clock();
    printf("��������%d ms\n", end - start);
    //��������
    start = clock();
    RadixCountSort(test3, LEN3);
    end = clock();
    printf("��������%d ms\n", end - start);

    system("pause");
    return 0;
}