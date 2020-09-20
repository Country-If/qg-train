#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "LinkStack.h"

Status initLStack(LinkStack *s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

Status isEmptyLStack(LinkStack *s)
{
    if(s->top == NULL)
    {
        return success;
    }
    else
    {
        return error;
    }
}

Status getTopLStack(LinkStack *s,ElemType *e)
{
    if(s->top == NULL)
    {
        printf("ջΪ��\n");
        return error;
    }
    else
    {
        e = &s->top->data;
        printf("ջ��Ԫ��Ϊ��%d", *e);
        return success;
    }
}

Status clearLStack(LinkStack *s)
{
    if(s->top == NULL)
    {
        printf("ջΪ��\n");
        return error;
    }
    else
    {
        s->top = NULL;
        return success;
    }
}

Status destroyLStack(LinkStack *s)
{
    while(!isEmptyLStack(s))
    {
        LinkStackPtr temp;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    return success;
}

Status LStackLength(LinkStack *s,int *length)
{
    if(s->top == NULL)
    {
        return error;
    }
    else
    {
        length = &s->count;
        printf("��ǰջ�ĳ���Ϊ%d", *length);
        return success;
    }
}

Status pushLStack(LinkStack *s,ElemType data)
{
    LinkStackPtr new = (LinkStackPtr)malloc(sizeof(StackNode));
    if(new == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;
    }
    new->data = data;
    new->next = s->top;
    s->top = new;
    s->count++;
    return success;
}

Status popLStack(LinkStack *s,ElemType *data)
{
    if(s->top == NULL)
    {
        printf("ջΪ��\n");
        return error;
    }
    else
    {
        LinkStackPtr temp;
        data = &s->top->data;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->count--;
        return success;
    }
}

void show(void)
{
    printf("\n\n\n\n        ��ջ\n");
    printf("     (ջ�ѳ�ʼ��)\n\n");
    printf("     1.�ж�ջ�Ƿ�Ϊ��\n");
    printf("     2.�õ�ջ��Ԫ��\n");
    printf("     3.���ջ\n");
    printf("     4.����ջ\n");
    printf("     5.���ջ�ĳ���\n");
    printf("     6.��ջ\n");
    printf("     7.��ջ\n");
    printf("     8.�˳�\n\n");
    printf("�������Ӧ������(1-8)��");
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
