#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "LinkStack.h"

int main(void)
{
    int choice;
    int *len = NULL;
    ElemType data;
    LinkStack s;
    ElemType *p = NULL;//���ڻ�ȡջ��Ԫ�ؼ������ջ��Ԫ��
    
    if(!initLStack(&s))
    {
        printf("ջ��ʼ��ʧ��\n");
    }

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://�ж�ջ�Ƿ�Ϊ��
            {
                if(isEmptyLStack(&s))
                {
                    printf("ջΪ��\n");
                }
                else
                {
                    printf("ջ�ǿ�\n");
                }
                break;
            }
            case 2://�õ�ջ��Ԫ��
            {
                if(!getTopLStack(&s, p))
                {
                    printf("��ȡʧ��\n");
                }
                break;
            }
            case 3://���ջ
            {
                if(clearLStack(&s))
                {
                    printf("������\n");
                }
                else
                {
                    printf("���ʧ��\n");
                }
                break;
            }
            case 4://����ջ
            {
                if(destroyLStack(&s))
                {
                    printf("�������\n");
                }
                else
                {
                    printf("����ʧ��\n");
                }
                break;
            }
            case 5://���ջ�ĳ���
            {
                if(!LStackLength(&s, len))
                {
                    printf("ջΪ��\n");
                }
                break;
            }
            case 6://��ջ
            {
                printf("���������ݣ�");
                scanf("%d", &data);
                if(!pushLStack(&s, data))
                {
                    printf("��ջʧ��\n");
                }
                break;
            }
            case 7://��ջ
            {
                if(popLStack(&s, p))
                {
                    printf("��ջ���\n");
                }
                else
                {
                    printf("��ջʧ��\n");
                }
                break;
            }
            case 8://�˳�����
            {
                break;
            }
            default:
            {
                printf("�������������֣�(1-8)\n");
                break;
            }
        }
    } while (choice != 8);

    return 0;
}
