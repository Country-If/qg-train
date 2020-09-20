#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "linkedList.h"

void show();

void show()
{
    system("CLS");
    //下面是交互式界面
    printf("\n\n\n\n单链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.插入数据\n");
    printf("4.删除数据\n");
    printf("5.遍历链表\n");
    printf("6.查找数据\n");
    printf("7.反转链表\n");
    printf("8.判断链表是否成环\n");
    printf("9.反转链表中的偶数结点/无此功能\n");//不会写 
    printf("10.查找中间结点\n");
    printf("11.退出\n");
    printf("\n请输入对应数字(1-11)：");
}


int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;

    do
    {
    	show();    
    	scanf("%d", &choice);
        switch(choice)
        {
            case 1: //创建空链表
            {
                if(InitList(&head))        
                {
                    printf("空链表创建成功\n");
                }
                else
                {
                    printf("空链表创建失败\n");
                }    
                break;       
            }
            case 2: //销毁链表
            {           
                DestroyList(&head);
                printf("链表销毁完成\n");
                break;
            }
            case 3: //插入数据
            {
            	if(head == NULL)
            	{
            		printf("链表为空，请先创建链表\n");
				}
				else
				{
					printf("请输入数据：");
                	scanf("%d", &num);
	                if(InsertList(head, num))
	                {
	                    printf("数据插入成功\n");
	                }
	                else
	                {
	                    printf("数据插入失败\n");
	                }
				}
                break;
            }
            case 4: //删除数据
            {
                printf("你想删除哪个数据：");
                scanf("%d", &num);
                if(DeleteList(head, num))
                {
                    printf("数据删除成功\n");
                }
                break;
            }
            case 5: //遍历链表 
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表不存在或者只存在一个空的头结点\n");
                }
                else
                {
                    TraverseList(head);
                }
                break;
            }
            case 6: //查找数据 
            {
                printf("请输入要查找的数据：");
                scanf("%d", &num);
                if(SearchList(head, num))
                {
                    printf("该数存在\n");
                }
                else
                {
                    printf("该数不存在\n");
                }
                break;
            }
            case 7: //反转链表 
            {
                if(head == NULL || head->next == NULL) //空链表或者链表只含两个结点(无需反转) 
                {
                    printf("空链表或者链表只含两个结点\n");
                }
                else
                {
                    if(ReverseList(&head))
                    {
                        printf("链表反转成功\n");
                    }
                    else
                    {
                        printf("链表反转失败\n");
                    }
                }
                break;
            }
            case 8: //判断链表是否成环 
            {
            	if(head == NULL || head->next == NULL)
            	{
            		printf("链表为空\n");
				}
				else
				{
					if(IsLoopList(head))
	                {
	                    printf("链表成环\n");
	                }
	                else
	                {
	                    printf("链表没有成环\n");
	                }
				}
                break;
            }
            case 9: //反转链表中的偶数结点 
            {
                break;
            }
            case 10: //查找中间结点 
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("这是空链表\n");
                }
                else
                {
                    printf("链表中间存储的值为%d\n", (FindMidNode(head))->data);
                }
                break;
            }
            case 11: //销毁链表 
            {
                DestroyList(&head);
                goto end;
            }
            default:
            {
            	printf("请重新输入数字!(1-11)\n");
				break;		
			}
        }
        getchar();
        system("pause");
    }while(1);

end:
	
    return 0;
}
