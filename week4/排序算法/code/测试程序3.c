#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include "function.c"

#define RANGE 1000 //�������Χ
#define LEN1 10000
#define LEN2 50000
#define LEN3 200000
#define LEN 200000
#define BUFFER 10
#define N 100000 //ִ�д���
#define M 100 //ÿ������ĳ���

int main(void)
{
    FILE *fp;
    int i, j, max;
    int *temp;
    int test[LEN], data[M];
    clock_t start, end;
    
    if((fp = fopen("data.txt", "w")) == NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(1);
    }
    for(i = 0; i < LEN; i++)
    {
        fprintf(fp,"%d ", rand() % RANGE);
    }
    fclose(fp);

    if((fp = fopen("data.txt","r")) == NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(1);
    }
    i = 0;
    while((fscanf(fp, "%d", &test[i])) != EOF)
    {
        i++;
    }
    fclose(fp);
    
    //�����ݲ���
    printf("������Բ�ͬ�����ݵ��������\n");
    printf("������%d�����ݵ����������\n", LEN1);
    //��������
    start = clock();
    insertSort(test, LEN1);
    end = clock();
    printf("��������%d ms\n", end - start);
    //�鲢����
    start = clock();
    temp = (int *)malloc(sizeof(int) * LEN1);
    if(temp == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    start = clock();
    MergeSort(test, 0, LEN1 - 1, temp);
    end = clock();
    free(temp);
    printf("�鲢����%d ms\n", end - start);
    //��������(�ݹ�)
    start = clock();
    QuickSort_Recursion(test, 0, LEN1 - 1);
    end = clock();
    printf("��������(�ݹ�)��%d ms\n", end - start);
    //��������(������)
    start = clock();
    PartitionQuickSort(test, 0, LEN1 - 1);
    end = clock();
    printf("��������(������)��%d ms\n", end - start);
    //��������
    start = clock();
    max = arrayMax(test, LEN1);
    CountSort(test, LEN1, max);
    end = clock();
    printf("��������%d ms\n", end - start);
    //��������
    start = clock();
    RadixCountSort(test, LEN1);
    end = clock();
    printf("��������%d ms\n", end - start);

    printf("������%d�����ݵ����������\n", LEN2);
    //��������
    start = clock();
    insertSort(test, LEN2);
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
    MergeSort(test, 0, LEN2 - 1, temp);
    end = clock();
    printf("�鲢����%d ms\n", end - start);
    free(temp);
    //��������(�ݹ�)
    start = clock();
    QuickSort_Recursion(test, 0, LEN2 - 1);
    end = clock();
    printf("��������(�ݹ�)��%d ms\n", end - start);
    //��������(������)
    start = clock();
    PartitionQuickSort(test, 0, LEN2 - 1);
    end = clock();
    printf("��������(������)��%d ms\n", end - start);
    //��������
    start = clock();
    max = arrayMax(test, LEN2);
    CountSort(test, LEN2, max);
    end = clock();
    printf("��������%d ms\n", end - start);
    //��������
    start = clock();
    RadixCountSort(test, LEN2);
    end = clock();
    printf("��������%d ms\n", end - start);

    printf("������%d�����ݵ����������\n", LEN3);
    //��������
    start = clock();
    insertSort(test, LEN3);
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
    MergeSort(test, 0, LEN3 - 1, temp);
    end = clock();
    printf("�鲢����%d ms\n", end - start);
    free(temp);
    //��������(�ݹ�)
    start = clock();
    QuickSort_Recursion(test, 0, LEN3 - 1);
    end = clock();
    printf("��������(�ݹ�)��%d ms\n", end - start);
    //��������(������)
    start = clock();
    PartitionQuickSort(test, 0, LEN3 - 1);
    end = clock();
    printf("��������(������)��%d ms\n", end - start);
    //��������
    start = clock();
    max = arrayMax(test, LEN3);
    CountSort(test, LEN3, max);
    end = clock();
    printf("��������%d ms\n", end - start);
    //��������
    start = clock();
    RadixCountSort(test, LEN3);
    end = clock();
    printf("��������%d ms\n", end - start);

    /* //���Դ���С����,����д�ҵ�˼·
    printf("\n������Դ���С����\n");
    start = clock();
    //����100k������ÿ�ζԴ�СΪ100�������������
    for(i = 0; i < N; i++)
    {
        //���ɴ�СΪ100�����ݣ�д��txt
        if((fp = fopen("data.txt", "w")) == NULL)
        {
            printf("�ļ���ʧ��\n");
            exit(1);
        }
        for(j = 0; j < M; i++)
        {
            fprintf(fp,"%d ", rand() % RANGE);
        }
        fclose(fp);
        //��ȡtxt���ݣ����浽����
        if((fp = fopen("data.txt","r")) == NULL)
        {
            printf("�ļ���ʧ��\n");
            exit(1);
        }
        j = 0;
        while((fscanf(fp, "%d", &test[j])) != EOF)
        {
            j++;
        }
        fclose(fp);
        //��������ĺ�����������
        //function
    }
    end = clock();
    printf("����%d ms\n", end - start); */

    system("pause");
    return 0;
}