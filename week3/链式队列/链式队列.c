#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

//链式队列
#define LQUEUE_H_INCLUDED

typedef int ElemType;

typedef struct node
{
    void *data; //数据域指针
    struct node *next; //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front; //队头
    Node *rear; //队尾
    int length; //队列长度
} LQueue;

typedef enum
{
    error, success
} Status;

void InitLQueue(LQueue *Q); //初始化队列
void DestoryLQueue(LQueue *Q); //销毁队列
Status IsEmptyLQueue(const LQueue *Q); //检查队列是否为空
Status GetHeadLQueue(LQueue *Q, void *e); //查看队头元素
int LengthLQueue(LQueue *Q); //确定队列长度
Status EnLQueue(LQueue *Q, void *data); //入队操作
Status DeLQueue(LQueue *Q); //出队操作
void ClearLQueue(LQueue *Q); //清空队列
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)); //遍历队列
void LPrint(void *q); //操作函数
void show(void);//显示界面
int judge_int(void);//使用户输入整数

//下面是具体函数操作
void InitLQueue(LQueue *Q)
{
    Node *head = (Node *)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    head->next = NULL;
    Q->front = Q->rear = head;
    Q->length = 0;
}

void DestoryLQueue(LQueue *Q)
{
    if(Q->front->next != NULL)//如果队列非空
    {
        ClearLQueue(Q);//先清空队列
    }
    free(Q->front);//再释放头结点
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
        printf("队列为空\n");
        return error;
    }
    else
    {
        memcpy(e, Q->front->next->data, sizeof(ElemType));
        printf("队头元素为：");
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
        printf("队列未初始化\n");
        return error;
    }
    else if(Q->front->next == NULL)
    {
        printf("队列为空\n");
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
    printf("\n\n\n\n\t  循环队列\n\n");
    printf("\t1.初始化队列\n");
    printf("\t2.销毁队列\n");
    printf("\t3.检查队列是否为空\n");
    printf("\t4.查看队头元素\n");
    printf("\t5.确定队列长度\n");
    printf("\t6.入队\n");
    printf("\t7.出队\n");
    printf("\t8.清空队列\n");
    printf("\t9.遍历队列\n");
    printf("\t10.退出\n\n");
    printf("请输入对应的数字(1-10)：");
}

int judge_int(void) //防止用户乱输入其他的字符
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
            if(word[m]<'0' || word[m]>'9') //检验是否有乱输入其他字符
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
    for(m=0;m<len;m++) // 将字符重新转换为数字
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
            case 1://初始化队列
            {
                InitLQueue(&Q);
                printf("队列初始化完成\n");
                break;
            }
            case 2://销毁队列
            {
                if(Q.front == NULL)
                {
                    printf("队列未初始化\n");
                }
                else
                {
                    DestoryLQueue(&Q);
                    printf("销毁完成\n");
                }
                break;
            }
            case 3://检查队列是否为空
            {
                if(Q.front == NULL)
                {
                    printf("队列未初始化\n");
                }
                else
                {
                    if(IsEmptyLQueue(&Q))
                    {
                        printf("队列为空\n");
                    }
                    else
                    {
                        printf("队列非空\n");
                    }
                }
                break;
            }
            case 4://查看队头元素
            {
                if(Q.front == NULL)
                {
                    printf("队列未初始化\n");
                }
                else
                {
                    if(!GetHeadLQueue(&Q, &data))
                    {
                        printf("查看失败\n");
                    }
                }
                break;
            }
            case 5://确定队列长度
            {
                if(Q.front == NULL)
                {
                    printf("队列未初始化\n");
                }
                else
                {
                    int len;
                    len = LengthLQueue(&Q);
                    printf("队列长度为：%d", len);
                }
                break;
            }
            case 6://入队
            {
                if(Q.front == NULL)
                {
                    printf("队列未初始化\n");
                }
                else 
                {
                    printf("请输入数据：");
                    scanf("%d", &data);
                    if(EnLQueue(&Q, &data))
                    {
                        printf("入队完成\n");
                    }
                    else
                    {
                        printf("入队失败\n");
                    }
                }
                break;
            }
            case 7://出队
            {
                if(DeLQueue(&Q))
                {
                    printf("出队完成\n");
                }
                else
                {
                    printf("出队失败\n");
                }
                break;
            }
            case 8://清空队列
            {
                if(Q.front == NULL)
                {
                    printf("队列未初始化\n");
                }
                else
                {
                    ClearLQueue(&Q);
                    printf("清空完成\n");
                }
                break;
            }
            case 9://遍历队列
            {
                if(Q.front == NULL)
                {
                    printf("队列未初始化\n");
                }
                else if(Q.front->next == NULL)
                {
                    printf("队列为空\n");
                }
                else
                {
                    TraverseLQueue(&Q, LPrint);
                }
                break;
            }
            case 10://退出
            {
                break;
            }
            default:
            {
                printf("请重新输入数字(1-10)！\n");
                break;
            }
        }
    } while (choice != 10);

    return 0;
}