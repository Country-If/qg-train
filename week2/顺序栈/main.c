#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "SqStack.h"

int main(void)
{
    SqStack s;
    s.elem = NULL;
    int choice, size, data;
    ElemType *p = NULL;//���ڻ�ȡջ��Ԫ���Լ����ջ�ĳ���
    ElemType *temp = NULL;//���ڴ���pop��ȥ��ֵ

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://��ʼ��ջ
            {
                printf("������ջ�ĳ��ȣ�");
                scanf("%d", &size);
                if(initStack(&s, size))
                {
                    printf("��ʼ���ɹ�\n");
                }
                else 
                {
                    printf("��ʼ��ʧ��\n");
                }
                break;
            }
            case 2://�ж�ջ�Ƿ�Ϊ��
            {
                if(s.elem == NULL)
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                else 
                {
                    if(isEmptyStack(&s))
                    {
                        printf("ջΪ��\n");
                    }
                    else 
                    {
                        printf("ջ�ǿ�\n");
                    }
                }
                break;
            }
            case 3://�õ�ջ��Ԫ��
            {
                if(!getTopStack(&s, p))
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                break;
            }
            case 4://���ջ
            {
                if(clearStack(&s))
                {
                    printf("������\n");
                }
                else 
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                break;
            }
            case 5://����ջ
            {
                if(destroyStack(&s))
                {
                    printf("ջ�������\n");
                }
                else 
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                break;
            }
            case 6://���ջ�ĳ���
            {
                if(!stackLength(&s, p))
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                break;
            }
            case 7://��ջ
            {
                if(s.elem == NULL)
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                else if(s.top == s.size - 1)
                {
                    printf("ջ��\n");
                    printf("��ջʧ��\n");
                }
                else 
                {
                    printf("���������ݣ�");
                    scanf("%d", &data);
                    if(!pushStack(&s, data))
                    {
                        printf("��ջʧ��\n");
                    }
                    else 
                    {
                        printf("��ջ���\n");
                    }
                }
                break;
            }
            case 8://��ջ
            {
                if(s.elem == NULL)
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                else
                {
                    if(popStack(&s, temp))
                    {
                        printf("��ջ�ɹ�\n");
                    }
                    else 
                    {
                        printf("��ջʧ��\n");
                    }
                }
                break;
            }
            case 9://�˳�����
            {
                break;
            }
            default:
            {
                printf("�������������֣�(1-9)\n");
                break;
            }
        }
    } while (choice != 9);

    return 0;
}
