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
    ElemType *p = NULL;//用于获取栈顶元素及储存出栈的元素
    
    if(!initLStack(&s))
    {
        printf("栈初始化失败\n");
    }

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://判断栈是否为空
            {
                if(isEmptyLStack(&s))
                {
                    printf("栈为空\n");
                }
                else
                {
                    printf("栈非空\n");
                }
                break;
            }
            case 2://得到栈顶元素
            {
                if(!getTopLStack(&s, p))
                {
                    printf("获取失败\n");
                }
                break;
            }
            case 3://清空栈
            {
                if(clearLStack(&s))
                {
                    printf("清空完成\n");
                }
                else
                {
                    printf("清空失败\n");
                }
                break;
            }
            case 4://销毁栈
            {
                if(destroyLStack(&s))
                {
                    printf("销毁完成\n");
                }
                else
                {
                    printf("销毁失败\n");
                }
                break;
            }
            case 5://检测栈的长度
            {
                if(!LStackLength(&s, len))
                {
                    printf("栈为空\n");
                }
                break;
            }
            case 6://入栈
            {
                printf("请输入数据：");
                scanf("%d", &data);
                if(!pushLStack(&s, data))
                {
                    printf("入栈失败\n");
                }
                break;
            }
            case 7://出栈
            {
                if(popLStack(&s, p))
                {
                    printf("出栈完成\n");
                }
                else
                {
                    printf("出栈失败\n");
                }
                break;
            }
            case 8://退出程序
            {
                break;
            }
            default:
            {
                printf("请重新输入数字！(1-8)\n");
                break;
            }
        }
    } while (choice != 8);

    return 0;
}
