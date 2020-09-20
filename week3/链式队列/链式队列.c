#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

//��ʽ����
#define LQUEUE_H_INCLUDED

typedef int ElemType;

typedef struct node
{
    void *data; //������ָ��
    struct node *next; //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front; //��ͷ
    Node *rear; //��β
    int length; //���г���
} LQueue;

typedef enum
{
    error, success
} Status;

void InitLQueue(LQueue *Q); //��ʼ������
void DestoryLQueue(LQueue *Q); //���ٶ���
Status IsEmptyLQueue(const LQueue *Q); //�������Ƿ�Ϊ��
Status GetHeadLQueue(LQueue *Q, void *e); //�鿴��ͷԪ��
int LengthLQueue(LQueue *Q); //ȷ�����г���
Status EnLQueue(LQueue *Q, void *data); //��Ӳ���
Status DeLQueue(LQueue *Q); //���Ӳ���
void ClearLQueue(LQueue *Q); //��ն���
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)); //��������
void LPrint(void *q); //��������
void show(void);//��ʾ����
int judge_int(void);//ʹ�û���������

//�����Ǿ��庯������
void InitLQueue(LQueue *Q)
{
    Node *head = (Node *)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    head->next = NULL;
    Q->front = Q->rear = head;
    Q->length = 0;
}

void DestoryLQueue(LQueue *Q)
{
    if(Q->front->next != NULL)//������зǿ�
    {
        ClearLQueue(Q);//����ն���
    }
    free(Q->front);//���ͷ�ͷ���
    Q->front = Q->rear = NULL;
}

Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->front->next == NULL)
    {
        return success;
    }
    else
    {
        return error;
    }
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(Q->front->next == NULL)
    {
        printf("����Ϊ��\n");
        return error;
    }
    else
    {
        memcpy(e, Q->front->next->data, sizeof(ElemType));
        printf("��ͷԪ��Ϊ��");
        LPrint(e);
        return success;
    }
}

int LengthLQueue(LQueue *Q)
{
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = (void *)malloc(sizeof(Node));
    memcpy(p->data, data, sizeof(ElemType));
    Q->rear->next = p;
    Q->rear = p;
    p->next = NULL;
    Q->length++;
    return success;
}

Status DeLQueue(LQueue *Q)
{
    if(Q->front == NULL)
    {
        printf("����δ��ʼ��\n");
        return error;
    }
    else if(Q->front->next == NULL)
    {
        printf("����Ϊ��\n");
        return error;
    }
    else
    {
        Node *temp = Q->front->next;
        Q->front->next = temp->next;
        free(temp->data);
        free(temp);
        Q->length--;
        if(Q->length == 0)
        {
            Q->rear = Q->front;
        }
        return success;
    }
}

void ClearLQueue(LQueue *Q)
{
    Node *temp;
    temp = Q->front->next;
    while(Q->front->next != NULL)
    {
        Q->front->next = temp->next;
        free(temp->data);
        free(temp);
        temp = Q->front->next;
    }
    Q->rear = Q->front;
    Q->length = 0;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    Node *p;
    p = Q->front->next;
    while(p != NULL)
    {
        foo(p->data);
        p = p->next;
    }
    return success;
}

void LPrint(void *q)
{
    printf("%d\t", *(ElemType *)q);
}

void show(void)
{
    printf("\n\n\n\n\t  ѭ������\n\n");
    printf("\t1.��ʼ������\n");
    printf("\t2.���ٶ���\n");
    printf("\t3.�������Ƿ�Ϊ��\n");
    printf("\t4.�鿴��ͷԪ��\n");
    printf("\t5.ȷ�����г���\n");
    printf("\t6.���\n");
    printf("\t7.����\n");
    printf("\t8.��ն���\n");
    printf("\t9.��������\n");
    printf("\t10.�˳�\n\n");
    printf("�������Ӧ������(1-10)��");
}

int judge_int(void) //��ֹ�û��������������ַ�
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
            if(word[m]<'0' || word[m]>'9') //�����Ƿ��������������ַ�
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
    for(m=0;m<len;m++) // ���ַ�����ת��Ϊ����
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}

int main(void)
{
    int choice;
    ElemType data;
    LQueue Q;
    Q.front = Q.rear = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://��ʼ������
            {
                InitLQueue(&Q);
                printf("���г�ʼ�����\n");
                break;
            }
            case 2://���ٶ���
            {
                if(Q.front == NULL)
                {
                    printf("����δ��ʼ��\n");
                }
                else
                {
                    DestoryLQueue(&Q);
                    printf("�������\n");
                }
                break;
            }
            case 3://�������Ƿ�Ϊ��
            {
                if(Q.front == NULL)
                {
                    printf("����δ��ʼ��\n");
                }
                else
                {
                    if(IsEmptyLQueue(&Q))
                    {
                        printf("����Ϊ��\n");
                    }
                    else
                    {
                        printf("���зǿ�\n");
                    }
                }
                break;
            }
            case 4://�鿴��ͷԪ��
            {
                if(Q.front == NULL)
                {
                    printf("����δ��ʼ��\n");
                }
                else
                {
                    if(!GetHeadLQueue(&Q, &data))
                    {
                        printf("�鿴ʧ��\n");
                    }
                }
                break;
            }
            case 5://ȷ�����г���
            {
                if(Q.front == NULL)
                {
                    printf("����δ��ʼ��\n");
                }
                else
                {
                    int len;
                    len = LengthLQueue(&Q);
                    printf("���г���Ϊ��%d", len);
                }
                break;
            }
            case 6://���
            {
                if(Q.front == NULL)
                {
                    printf("����δ��ʼ��\n");
                }
                else 
                {
                    printf("���������ݣ�");
                    scanf("%d", &data);
                    if(EnLQueue(&Q, &data))
                    {
                        printf("������\n");
                    }
                    else
                    {
                        printf("���ʧ��\n");
                    }
                }
                break;
            }
            case 7://����
            {
                if(DeLQueue(&Q))
                {
                    printf("�������\n");
                }
                else
                {
                    printf("����ʧ��\n");
                }
                break;
            }
            case 8://��ն���
            {
                if(Q.front == NULL)
                {
                    printf("����δ��ʼ��\n");
                }
                else
                {
                    ClearLQueue(&Q);
                    printf("������\n");
                }
                break;
            }
            case 9://��������
            {
                if(Q.front == NULL)
                {
                    printf("����δ��ʼ��\n");
                }
                else if(Q.front->next == NULL)
                {
                    printf("����Ϊ��\n");
                }
                else
                {
                    TraverseLQueue(&Q, LPrint);
                }
                break;
            }
            case 10://�˳�
            {
                break;
            }
            default:
            {
                printf("��������������(1-10)��\n");
                break;
            }
        }
    } while (choice != 10);

    return 0;
}