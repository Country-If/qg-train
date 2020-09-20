#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "duLinkedList.h"

void show();

void show()
{
    system("cls");
    printf("\n\n\n\n双链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.头插法插入数据\n");
    printf("4.尾插法插入数据\n");
    printf("5.删除数据\n");
    printf("6.遍历链表\n");
    printf("7.退出\n");
    printf("\n请输入对应的数字(1-7)：");
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
            case 1://创建空链表
            {
                if(InitList_DuL(&head))
                {
                    printf("空链表创建成功\n");
                }
                else
                {
                    printf("空链表创建失败\n");
                }
                break;
            }
            case 2://销毁链表
            {
                DestroyList_DuL(&head);
                printf("链表销毁成功\n");
                break;
            }
            case 3://头插法插入数据
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if(InsertBeforeList_DuL(head, newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 4://尾插法插入数据
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if(InsertAfterList_DuL(head, newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 5://删除数据
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    printf("你想删除哪个数据：");
                    scanf("%d", &num);
                    if(DeleteList_DuL(head, &num))
                    {
                        printf("数据删除成功\n");
                    }
                    else
                    {
                        printf("数据删除失败\n");
                    }
                }
                break;
            }
            case 6://遍历链表
            {
                TraverseList_DuL(head);
                break;
            }
            case 7://退出程序 
            {
                DestroyList_DuL(&head);
                goto end;
            }
            default:
            {
                printf("请重新输入数字!(1-7)\n");
                break;
            }
        }
        getchar();
        system("pause");
    } while (1);

end:

    return 0;
}
