#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//循环队列
#define AQUEUE_H_INCLUDED
#define MAXQUEUE 4 //最大队列长度

typedef int ElemType;

typedef struct Aqueue
{
    void *data[MAXQUEUE]; //数据域(指针数组)
    int front;
    int rear;
    int length; //队列长度
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

//函数声明
void InitAQueue(AQueue *Q); //初始化队列
void DestoryAQueue(AQueue *Q); //销毁队列
Status IsFullAQueue(const AQueue *Q); //检查队列是否已满
Status IsEmptyAQueue(const AQueue *Q); //检查队列是否为空
Status GetHeadAQueue(AQueue *Q, void *e); //查看队头元素
int LengthAQueue(AQueue *Q); //确定队列长度
Status EnAQueue(AQueue *Q, void *data);	//入队操作
Status DeAQueue(AQueue *Q);	//出队操作
void ClearAQueue(AQueue *Q); //清空队列
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)); //遍历队列
void APrint(void *q); //操作函数
void show(void);//显示界面
int judge_int(void);//使用户输入整数

//下面是具体函数操作
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
        printf("队列为空\n");
        return error;
    }
    else
    {
        e = Q->data[Q->front];
        printf("队头元素为：%d", *(ElemType *)e);
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
        printf("内存分配失败\n");
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
        printf("队列为空\n");
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
        printf("队列为空\n");
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
    printf("\n\n\n\n\t  循环队列\n");
    printf("\t 队列已初始化\n\n");
    printf("\t1.销毁队列\n");
    printf("\t2.检查队列是否已满\n");
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
            case 1://销毁队列
            {
                if(Q.length != 0)
                {
                    DestoryAQueue(&Q);
                }
                printf("队列销毁完成\n");
                break;
            }
            case 2://检查队列是否已满
            {
                if(IsFullAQueue(&Q))
                {
                    printf("队列已满\n");
                }
                else
                {
                    printf("队列未满\n");
                }
                break;
            }
            case 3://检查队列是否为空
            {
                if(IsEmptyAQueue(&Q))
                {
                    printf("队列为空\n");
                }
                else
                {
                    printf("队列非空\n");
                }
                break;
            }
            case 4://查看队头元素
            {
                if(!GetHeadAQueue(&Q, &data))
                {
                    printf("查看失败\n");
                }
                break;
            }
            case 5://确定队列长度
            {
                len = LengthAQueue(&Q);
                printf("队列长度为：%d", len);
                break;
            }
            case 6://入队
            {
                if(Q.length == MAXQUEUE)
                {
                    printf("队列已满\n入队失败\n");
                }
                else 
                {
                    printf("请输入数据：");
                    scanf("%d", &data);
                    if(EnAQueue(&Q, &data))
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
                if(DeAQueue(&Q))
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
                ClearAQueue(&Q);
                printf("队列清空完成\n");
                break;
            }
            case 9://遍历队列
            {
                if(!TraverseAQueue(&Q, APrint))
                {
                    printf("遍历失败\n");
                }
                break;
            }
            case 10://退出
            {
                break;
            }
            default:
            {
                printf("请重新输入数字！(1-10)\n");
                break;
            }
        }
    } while (choice != 10);

    return 0;
}