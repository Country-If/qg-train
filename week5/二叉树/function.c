#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LinkBiTree.h"

Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return success;
}

Status DestroyBiTree(BiTree *T)
{
    if(*T == NULL)
    {
        return error;
    }
    DestroyBiTree(&(*T)->lchild);
    DestroyBiTree(&(*T)->rchild);
    free(*T);
    return success;
}

Status CreateBiTree(BiTree *T, char *definition)
{
    scanf("%c", definition);
    if(*definition == '\n' || *definition == ' ') //���˻س��Ϳո�
    {
        scanf("%c", definition);
    }
    if(*definition == '#')
    {
        *T = NULL;
    }
    else 
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(*T == NULL)
        {
            printf("�ڴ����ʧ��\n");
            system("pause");
            exit(0);
        }
        (*T)->data = *definition;
        CreateBiTree(&(*T)->lchild, definition);
        CreateBiTree(&(*T)->rchild, definition);
    }
}

Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T != NULL)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
        return success;
    }
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T != NULL)
    {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
        return success;
    }
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T != NULL)
    {
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
        return success;
    }
}

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    pQueue Q = (pQueue)malloc(sizeof(Queue));
    Q->front = Q->rear = NULL;
    EnQueue(Q, T);
    while(Q->front != NULL)
    {
        BiTree x = (BiTree)malloc(sizeof(BiTNode));
        if(x == NULL)
        {
            printf("�ڴ����ʧ��\n");
            system("pause");
            exit(0);
        }
        x = DeQueue(Q);
        visit(x->data);
        if(x->lchild != NULL)
        {
            EnQueue(Q, x->lchild);
        }
        if(x->rchild != NULL)
        {
            EnQueue(Q, x->rchild);
        }
        free(x);
    }
    free(Q);
    return success;
}

Status EnQueue(pQueue Q, BiTree data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = (BiTree)malloc(sizeof(BiTNode));
    if(newNode == NULL || newNode->data == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    memcpy(newNode->data, data, sizeof(BiTNode));
    newNode->next = NULL;
    if(Q->front == NULL)
    {
        Q->front = newNode;
        Q->rear = newNode;
    }
    else 
    {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    return success;
}

BiTree DeQueue(pQueue Q)
{
    BiTree data = (BiTree)malloc(sizeof(BiTNode));
    if(data == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    QueueNode *temp = Q->front;
    *data = *(Q->front->data);
    if(Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        Q->front = temp->next;
    }
    free(temp->data);
    free(temp);
    return data;
}

Status visit(TElemType e)
{
    printf("%c\t", e);
    return success;
}

Status CreatePolish(BiTree *T)
{
    char ch;
    scanf("%c", &ch);
    if(ch == '\n' || ch == ' ') //���˻س��Ϳո�
    {
        scanf("%c", &ch);
    }
    if('0' <= ch && ch <= '9')
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(*T == NULL)
        {
            printf("�ڴ����ʧ��\n");
            system("pause");
            exit(0);
        }
        (*T)->data = ch;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(*T == NULL)
        {
            printf("�ڴ����ʧ��\n");
            system("pause");
            exit(0);
        }
        (*T)->data = ch;
        CreatePolish(&(*T)->lchild);
        CreatePolish(&(*T)->rchild);
    }
    else 
    {
        printf("������������������\n");
        return error;
    }
    return success;
}

int Value(BiTree T)
{
    char ch = T->data;
    if('0' <= ch && ch <= '9')
    {
        return (int)(ch - '0');
    }
    else 
    {
        int left = Value(T->lchild);
        int right = Value(T->rchild);
        switch(ch)
        {
            case '+' : return (left + right);
            case '-' : return (left - right);
            case '*' : return (left * right);
            case '/' :
            {
                if(right == 0)
                {
                    printf("������������Ϊ0\n");
                    system("pause");
                    exit(0);
                }
                else 
                {
                    return (left / right);
                }
            }
            default:
            {
                printf("����\n");
                break;
            }
        }
    }
}

void show(void)
{
    printf("\n\n\n\n        ������\n");
    printf("      �����Ѵ���\n");
    printf("     1.�ݻٶ�����\n");
    printf("     2.���������(���򴴽�)\n");
    printf("     3.�������\n");
    printf("     4.�������\n");
    printf("     5.�������\n");
    printf("     6.�������\n");
    printf("     7.����ǰ׺���ʽ������\n");
    printf("     0.�˳�\n\n");
    printf("�������Ӧ������(0-7)��");
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