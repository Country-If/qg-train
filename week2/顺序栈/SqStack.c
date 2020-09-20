#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "SqStack.h"

Status initStack(SqStack *s, int sizes)
{
    s->elem = (int *)malloc(sizeof(int) * sizes);
    s->size = sizes;
    s->top = -1;
    return success;
}

Status isEmptyStack(SqStack *s)
{
    if(s->top == -1)
    {
        return success;
    }
    else
    {
        return error;
    }
}

Status getTopStack(SqStack *s, ElemType *e)
{
    if(s->elem == NULL)
    {
        return error;
    }
    else 
    {
        if(s->top == -1)
        {
            printf("当前栈为空\n");
            return success;
        }
        else
        {
            e = s->elem + s->top;
            printf("当前栈顶元素是：%d\n", *e);
            return success;
        }
    }
}

Status clearStack(SqStack *s)
{
    if(s->elem == NULL)
    {
        return error;
    }
    else 
    {
        if(s->top == -1)
        {
            return success;
        }
        else 
        {
            s->top = -1;
            return success;
        }
    }
}

Status destroyStack(SqStack *s)
{
    if(s->elem == NULL)
    {
        return error;
    }
    else 
    {
        free(s->elem);
        s->elem = NULL;
        return success;
    }
}

Status stackLength(SqStack *s, int *length)
{
    if(s->elem == NULL)
    {
        return error;
    }
    else
    {
        length = &s->top;
        printf("当前栈的长度为%d\n", *length + 1);
        return success;
    }
    
}

Status pushStack(SqStack *s, ElemType data)
{
    s->top++;
    *(s->elem + s->top) = data;
    return success;
}

Status popStack(SqStack *s, ElemType *data)
{
    if(s->top == -1)
    {
        printf("栈为空\n");
        return error;
    }
    else
    {
        data = s->elem + s->top;
        s->top--;
        return success;
    }
}

void show()
{
    printf("\n\n\n\n        顺序栈\n\n");
    printf("     1.初始化栈\n");
    printf("     2.判断栈是否为空\n");
    printf("     3.得到栈顶元素\n");
    printf("     4.清空栈\n");
    printf("     5.销毁栈\n");
    printf("     6.检测栈的长度\n");
    printf("     7.入栈\n");
    printf("     8.出栈\n");
    printf("     9.退出\n\n");
    printf("请输入对应的数字(1-9)：");
}

int judge_int(void)  //防止用户乱输入其他的字符
{
    int len, num = 0, arg = 1;
    char word[10];  
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // 将字符重新转换为数字
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}  
