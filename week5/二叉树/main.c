#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "LinkBiTree.h"
#include "function.c"

int main(void)
{
    int choice;
    char data;
    BiTree T;

    //flag�ж����Ƿ�Ϊ��,����Ϊ1���ǿ�Ϊ0
    int flag = InitBiTree(&T);

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1: //�ݻٶ�����
            {
                if(flag == 1)
                {
                    printf("����\n�ݻ�ʧ��\n");
                }
                else 
                {
                    DestroyBiTree(&T);
                    printf("�ݻ����\n");
                    flag = 1;
                }
                break;
            }
            case 2: //���������
            {
                if(flag == 0) //���ͷ��ڴ��ٴ���
                {
                    printf("���ȴݻ����ٴ���\n");
                    printf("����ʧ��\n");
                }
                else 
                {
                    getchar();
                    printf("��������ʽ(#��ʾ�ս��)��\n");
                    if(CreateBiTree(&T, &data))
                    {
                        flag = 0;
                        printf("�������\n");
                    }
                    else
                    {
                        printf("����ʧ��\n");
                    }
                }
                break;
            }
            case 3: //�������
            {
                if(T == NULL || flag == 1)
                {
                    printf("����\n����ʧ��\n");
                }
                else 
                {
                    PreOrderTraverse(T, visit);
                }
                break;
            }
            case 4: //�������
            {
                if(T == NULL || flag == 1)
                {
                    printf("����\n����ʧ��\n");
                }
                else 
                {
                    InOrderTraverse(T, visit);
                }
                break;
            }
            case 5: //�������
            {
                if(T == NULL || flag == 1)
                {
                    printf("����\n����ʧ��\n");
                }
                else 
                {
                    PostOrderTraverse(T, visit);
                }
                break;
            }
            case 6: //��α���
            {
                if(T == NULL || flag == 1)
                {
                    printf("����\n����ʧ��\n");
                }
                else 
                {
                    LevelOrderTraverse(T, visit);
                }
                break;
            }
            case 7: //����ǰ׺���ʽ������
            {
                if(flag == 0)
                {
                    printf("���ȴݻ����ٴ���\n");
                    printf("����ʧ��\n");
                }
                else 
                {
                    printf("������ǰ׺���ʽ(����Ϊ��λ��)��\n");
                    if(CreatePolish(&T))
                    {
                        flag = 0;
                        printf("�����ɹ�\n");
                        printf("������Ϊ��%d", Value(T));
                    }
                    else 
                    {
                        printf("����ʧ��\n");
                    }
                }
                break;
            }
            case 0: //�˳�����
            {
                break;
            }
            default:
            {
                printf("�������������֣�(0-7)\n");
                break;
            }
        }
    } while (choice != 0);

    system("pause");
    return 0;
}