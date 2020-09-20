#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "SqStack.h"

int main(void)
{
    SqStack s;
    s.elem = NULL;
    int choice, size, data;
    ElemType *p = NULL;//用于获取栈顶元素以及检测栈的长度
    ElemType *temp = NULL;//用于储存pop出去的值

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://初始化栈
            {
                printf("请输入栈的长度：");
                scanf("%d", &size);
                if(initStack(&s, size))
                {
                    printf("初始化成功\n");
                }
                else 
                {
                    printf("初始化失败\n");
                }
                break;
            }
            case 2://判断栈是否为空
            {
                if(s.elem == NULL)
                {
                    printf("请先初始化栈\n");
                }
                else 
                {
                    if(isEmptyStack(&s))
                    {
                        printf("栈为空\n");
                    }
                    else 
                    {
                        printf("栈非空\n");
                    }
                }
                break;
            }
            case 3://得到栈顶元素
            {
                if(!getTopStack(&s, p))
                {
                    printf("请先初始化栈\n");
                }
                break;
            }
            case 4://清空栈
            {
                if(clearStack(&s))
                {
                    printf("清空完成\n");
                }
                else 
                {
                    printf("请先初始化栈\n");
                }
                break;
            }
            case 5://销毁栈
            {
                if(destroyStack(&s))
                {
                    printf("栈销毁完成\n");
                }
                else 
                {
                    printf("请先初始化栈\n");
                }
                break;
            }
            case 6://检测栈的长度
            {
                if(!stackLength(&s, p))
                {
                    printf("请先初始化栈\n");
                }
                break;
            }
            case 7://入栈
            {
                if(s.elem == NULL)
                {
                    printf("请先初始化栈\n");
                }
                else if(s.top == s.size - 1)
                {
                    printf("栈满\n");
                    printf("入栈失败\n");
                }
                else 
                {
                    printf("请输入数据：");
                    scanf("%d", &data);
                    if(!pushStack(&s, data))
                    {
                        printf("入栈失败\n");
                    }
                    else 
                    {
                        printf("入栈完成\n");
                    }
                }
                break;
            }
            case 8://出栈
            {
                if(s.elem == NULL)
                {
                    printf("请先初始化栈\n");
                }
                else
                {
                    if(popStack(&s, temp))
                    {
                        printf("出栈成功\n");
                    }
                    else 
                    {
                        printf("出栈失败\n");
                    }
                }
                break;
            }
            case 9://退出程序
            {
                break;
            }
            default:
            {
                printf("请重新输入数字！(1-9)\n");
                break;
            }
        }
    } while (choice != 9);

    return 0;
}
