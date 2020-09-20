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

    //flag判断树是否为空,树空为1，非空为0
    int flag = InitBiTree(&T);

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1: //摧毁二叉树
            {
                if(flag == 1)
                {
                    printf("空树\n摧毁失败\n");
                }
                else 
                {
                    DestroyBiTree(&T);
                    printf("摧毁完成\n");
                    flag = 1;
                }
                break;
            }
            case 2: //构造二叉树
            {
                if(flag == 0) //先释放内存再创建
                {
                    printf("请先摧毁树再创建\n");
                    printf("构造失败\n");
                }
                else 
                {
                    getchar();
                    printf("请输入表达式(#表示空结点)：\n");
                    if(CreateBiTree(&T, &data))
                    {
                        flag = 0;
                        printf("构造完成\n");
                    }
                    else
                    {
                        printf("构造失败\n");
                    }
                }
                break;
            }
            case 3: //先序遍历
            {
                if(T == NULL || flag == 1)
                {
                    printf("空树\n遍历失败\n");
                }
                else 
                {
                    PreOrderTraverse(T, visit);
                }
                break;
            }
            case 4: //中序遍历
            {
                if(T == NULL || flag == 1)
                {
                    printf("空树\n遍历失败\n");
                }
                else 
                {
                    InOrderTraverse(T, visit);
                }
                break;
            }
            case 5: //后序遍历
            {
                if(T == NULL || flag == 1)
                {
                    printf("空树\n遍历失败\n");
                }
                else 
                {
                    PostOrderTraverse(T, visit);
                }
                break;
            }
            case 6: //层次遍历
            {
                if(T == NULL || flag == 1)
                {
                    printf("空树\n遍历失败\n");
                }
                else 
                {
                    LevelOrderTraverse(T, visit);
                }
                break;
            }
            case 7: //输入前缀表达式计算结果
            {
                if(flag == 0)
                {
                    printf("请先摧毁树再创建\n");
                    printf("创建失败\n");
                }
                else 
                {
                    printf("请输入前缀表达式(数字为个位数)：\n");
                    if(CreatePolish(&T))
                    {
                        flag = 0;
                        printf("创建成功\n");
                        printf("计算结果为：%d", Value(T));
                    }
                    else 
                    {
                        printf("创建失败\n");
                    }
                }
                break;
            }
            case 0: //退出程序
            {
                break;
            }
            default:
            {
                printf("请重新输入数字！(0-7)\n");
                break;
            }
        }
    } while (choice != 0);

    system("pause");
    return 0;
}