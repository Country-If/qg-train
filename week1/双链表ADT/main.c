#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "duLinkedList.h"

void show();

void show()
{
    system("cls");
    printf("\n\n\n\n˫����ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.ͷ�巨��������\n");
    printf("4.β�巨��������\n");
    printf("5.ɾ������\n");
    printf("6.��������\n");
    printf("7.�˳�\n");
    printf("\n�������Ӧ������(1-7)��");
}

int main(void)
{
    int choice, num = 0;
    DuLinkedList head;
    head = NULL;

    do
    {
        show();
        scanf("%d", &choice);
        switch(choice)
        {
            case 1://����������
            {
                if(InitList_DuL(&head))
                {
                    printf("���������ɹ�\n");
                }
                else
                {
                    printf("��������ʧ��\n");
                }
                break;
            }
            case 2://��������
            {
                DestroyList_DuL(&head);
                printf("�������ٳɹ�\n");
                break;
            }
            case 3://ͷ�巨��������
            {
                if(head == NULL)
                {
                    printf("����δ���������ȴ�������\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("���������ݣ�");
                        scanf("%d", &newNode->data);
                        if(InsertBeforeList_DuL(head, newNode))
                        {
                            printf("���ݲ���ɹ�\n");
                        }
                        else
                        {
                            printf("���ݲ���ʧ��\n");
                        }
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                break;
            }
            case 4://β�巨��������
            {
                if(head == NULL)
                {
                    printf("����δ���������ȴ�������\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("���������ݣ�");
                        scanf("%d", &newNode->data);
                        if(InsertAfterList_DuL(head, newNode))
                        {
                            printf("���ݲ���ɹ�\n");
                        }
                        else
                        {
                            printf("���ݲ���ʧ��\n");
                        }
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                break;
            }
            case 5://ɾ������
            {
                if(head == NULL)
                {
                    printf("����δ���������ȴ�������\n");
                }
                else
                {
                    printf("����ɾ���ĸ����ݣ�");
                    scanf("%d", &num);
                    if(DeleteList_DuL(head, &num))
                    {
                        printf("����ɾ���ɹ�\n");
                    }
                    else
                    {
                        printf("����ɾ��ʧ��\n");
                    }
                }
                break;
            }
            case 6://��������
            {
                TraverseList_DuL(head);
                break;
            }
            case 7://�˳����� 
            {
                DestroyList_DuL(&head);
                goto end;
            }
            default:
            {
                printf("��������������!(1-7)\n");
                break;
            }
        }
        getchar();
        system("pause");
    } while (1);

end:

    return 0;
}
