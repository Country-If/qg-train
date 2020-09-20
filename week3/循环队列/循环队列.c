#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//ѭ������
#define AQUEUE_H_INCLUDED
#define MAXQUEUE 4 //�����г���

typedef int ElemType;

typedef struct Aqueue
{
    void *data[MAXQUEUE]; //������(ָ������)
    int front;
    int rear;
    int length; //���г���
}AQueue;

typedef struct node
{
    ElemType data;
    struct node *next;
}Node, *NodePtr;

typedef enum
{
    error, success
} Status;

//��������
void InitAQueue(AQueue *Q); //��ʼ������
void DestoryAQueue(AQueue *Q); //���ٶ���
Status IsFullAQueue(const AQueue *Q); //�������Ƿ�����
Status IsEmptyAQueue(const AQueue *Q); //�������Ƿ�Ϊ��
Status GetHeadAQueue(AQueue *Q, void *e); //�鿴��ͷԪ��
int LengthAQueue(AQueue *Q); //ȷ�����г���
Status EnAQueue(AQueue *Q, void *data);	//��Ӳ���
Status DeAQueue(AQueue *Q);	//���Ӳ���
void ClearAQueue(AQueue *Q); //��ն���
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)); //��������
void APrint(void *q); //��������
void show(void);//��ʾ����
int judge_int(void);//ʹ�û���������

//�����Ǿ��庯������
void InitAQueue(AQueue *Q)
{
    Q->front = Q->rear = Q->length = 0;
}

void DestoryAQueue(AQueue *Q)
{
    int i, n;
    n = (Q->rear + 1) % MAXQUEUE;
    for(i = 0; i < MAXQUEUE - 1; i++)
    {
        n = (n + 1) % MAXQUEUE;
        i++;
    }
    i = Q->front;
    while(i != n)
    {
        free(Q->data[i]);
        i++;
        i = i % MAXQUEUE;
    }
    free(Q->data[n]);
    Q->front = Q->rear = Q->length = 0;
}

Status IsFullAQueue(const AQueue *Q)
{
    if(Q->length == MAXQUEUE)
    {
        return success;
    }
    else
    {
        return error;
    }
}

Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->length == 0)
    {
        return success;
    }
    else
    {
        return error;
    }
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(Q->length == 0)
    {
        printf("����Ϊ��\n");
        return error;
    }
    else
    {
        e = Q->data[Q->front];
        printf("��ͷԪ��Ϊ��%d", *(ElemType *)e);
        return success;
    }
}

int LengthAQueue(AQueue *Q)
{
    return Q->length;
}

Status EnAQueue(AQueue *Q, void *data)
{
    NodePtr new = (NodePtr)malloc(sizeof(Node));
    if(new == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    new->data = *(ElemType *)data;
    new->next = NULL;
    Q->data[Q->rear] = new;
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->length++;
    return success;
}

Status DeAQueue(AQueue *Q)
{
    if(Q->length == 0)
    {
        printf("����Ϊ��\n");
        return error;
    }
    else
    {
        Q->front = (Q->front + 1) % MAXQUEUE;
        Q->length--;
        return success;
    }
}

void ClearAQueue(AQueue *Q)
{
    for(int i = 0; i < Q->length; i++)
    {
        DeAQueue(Q);
    }
    Q->front = Q->rear = Q->length = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(Q->length == 0)
    {
        printf("����Ϊ��\n");
        return error;
    }
    else
    {
        int i, n;
        n = (Q->rear + 1) % MAXQUEUE;
        for(i = 0; i < MAXQUEUE - 1; i++)
        {
            n = (n + 1) % MAXQUEUE;
            i++;
        }
        i = Q->front;
        while(i != n)
        {
            foo(Q->data[i]);
            i++;
            i = i % MAXQUEUE;
        }
        foo(Q->data[n]);
        return success;
    }
}

void APrint(void *q)
{
    printf("%d\t", *(ElemType *)q);
}

void show(void)
{
    printf("\n\n\n\n\t  ѭ������\n");
    printf("\t �����ѳ�ʼ��\n\n");
    printf("\t1.���ٶ���\n");
    printf("\t2.�������Ƿ�����\n");
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
    int choice, len;
    ElemType data;
    AQueue Q; 

    InitAQueue(&Q);

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://���ٶ���
            {
                if(Q.length != 0)
                {
                    DestoryAQueue(&Q);
                }
                printf("�����������\n");
                break;
            }
            case 2://�������Ƿ�����
            {
                if(IsFullAQueue(&Q))
                {
                    printf("��������\n");
                }
                else
                {
                    printf("����δ��\n");
                }
                break;
            }
            case 3://�������Ƿ�Ϊ��
            {
                if(IsEmptyAQueue(&Q))
                {
                    printf("����Ϊ��\n");
                }
                else
                {
                    printf("���зǿ�\n");
                }
                break;
            }
            case 4://�鿴��ͷԪ��
            {
                if(!GetHeadAQueue(&Q, &data))
                {
                    printf("�鿴ʧ��\n");
                }
                break;
            }
            case 5://ȷ�����г���
            {
                len = LengthAQueue(&Q);
                printf("���г���Ϊ��%d", len);
                break;
            }
            case 6://���
            {
                if(Q.length == MAXQUEUE)
                {
                    printf("��������\n���ʧ��\n");
                }
                else 
                {
                    printf("���������ݣ�");
                    scanf("%d", &data);
                    if(EnAQueue(&Q, &data))
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
                if(DeAQueue(&Q))
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
                ClearAQueue(&Q);
                printf("����������\n");
                break;
            }
            case 9://��������
            {
                if(!TraverseAQueue(&Q, APrint))
                {
                    printf("����ʧ��\n");
                }
                break;
            }
            case 10://�˳�
            {
                break;
            }
            default:
            {
                printf("�������������֣�(1-10)\n");
                break;
            }
        }
    } while (choice != 10);

    return 0;
}