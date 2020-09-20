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
            printf("��ǰջΪ��\n");
            return success;
        }
        else
        {
            e = s->elem + s->top;
            printf("��ǰջ��Ԫ���ǣ�%d\n", *e);
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
        printf("��ǰջ�ĳ���Ϊ%d\n", *length + 1);
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
        printf("ջΪ��\n");
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
    printf("\n\n\n\n        ˳��ջ\n\n");
    printf("     1.��ʼ��ջ\n");
    printf("     2.�ж�ջ�Ƿ�Ϊ��\n");
    printf("     3.�õ�ջ��Ԫ��\n");
    printf("     4.���ջ\n");
    printf("     5.����ջ\n");
    printf("     6.���ջ�ĳ���\n");
    printf("     7.��ջ\n");
    printf("     8.��ջ\n");
    printf("     9.�˳�\n\n");
    printf("�������Ӧ������(1-9)��");
}

int judge_int(void)  //��ֹ�û��������������ַ�
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
            if(word[m]<'0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
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
    for(m=0;m<len;m++)  // ���ַ�����ת��Ϊ����
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}  
