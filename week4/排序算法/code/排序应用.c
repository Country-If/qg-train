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
    int *data; //�������
    int *colorArray; //��ɫ��������

    printf("û��д���������̵Ĺ��ܣ����Ե�ʱ���밴Ҫ�����룡\n");
    //¼�����鳤��
    printf("���������鳤�ȣ�");
    scanf("%d", &len1);
    
    data = (int *)malloc(sizeof(int) * len1);
    if(data == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    printf("��¼����������(�Իس����)��\n");
    for(i = 0; i < len1; i++)
    {
        scanf("%d", data + i);
    }
    printf("����¼�����\n¼�������Ϊ��\n");
    for(i = 0; i < len1; i++)
    {
        printf("%d\t", *(data + i));
    }
    printf("\n");

    //�ҵ�K�����
    printf("�����ҵڼ��������");
    scanf("%d", &k);
    kNum = FindKNum(data, len1, k);
    if(kNum == -1)
    {
        printf("����Խ��\n");
    }
    else
    {
        printf("��K�����Ϊ��%d\n", kNum);
    }

    //¼�����鳤��
    printf("���������鳤�ȣ�");
    scanf("%d", &len2);

    colorArray = (int *)malloc(sizeof(int) * len2);
    if(colorArray == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        return -1;
    }
    for(i = 0; i < len2; i++)
    {
        colorArray[i] = rand() % 3;
    }
    printf("��ɫ��������������飺\n");
    for(i = 0; i < len2; i++)
    {
        printf("%d\t", colorArray[i]);
    }
    printf("\n");

    //��ɫ����
    ColorSort(colorArray, len2);
    printf("��ɫ��������飺\n");
    for(i = 0; i < len2; i++)
    {
        printf("%d\t", colorArray[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
