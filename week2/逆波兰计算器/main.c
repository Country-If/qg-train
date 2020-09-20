#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

#define STACK_H_INCLUDED
#define DATASIZE 50//��ź�׺���ʽ�����鳤��
#define MAXBUFFER 10//��󻺳�����С 

typedef char ElemType;
typedef int elemtype;

typedef enum Status 
{
    error, 
	success
} Status;

typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

typedef struct stacknode
{
	elemtype data;
	struct stacknode *next;
}stacknode, *linkstackptr;

typedef struct linkstack
{
	linkstackptr top;
	int	count;
}linkstack;

//����������(��ջ)
//ջ��Ԫ��Ϊ�ַ��ͣ����ڴ������������ 
Status initLStack(LinkStack *s);//��ʼ��ջ
Status notEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
void Push(LinkStack *s,ElemType data);//��ջ
void Pop(LinkStack *s,ElemType *data);//��ջ
//ջ��Ԫ��Ϊ���ͣ����ڴ������������ 
Status initlstack(linkstack *s);//��ʼ��ջ
void push(linkstack *s,elemtype data);//��ջ
void pop(linkstack *s,elemtype *data);//��ջ

//�������ַ�����ջ���������ĺ��� 
Status initLStack(LinkStack *s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

Status notEmptyLStack(LinkStack *s)
{
    if(s->top != NULL)//�ǿշ���1
    {
        return success;
    }
    else
    {
        return error;
    }
}

void Push(LinkStack *s,ElemType data)
{
    LinkStackPtr new = (LinkStackPtr)malloc(sizeof(StackNode));
    if(new == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    new->data = data;
    new->next = s->top;
    s->top = new;
    s->count++;
}
 
void Pop(LinkStack *s,ElemType *data)
{
    if(s->top == NULL)
    {
        printf("ջ��\n");
        system("pause");
        exit(0);
    }
    else
    {
        LinkStackPtr temp;
        *data = s->top->data;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->count--;
    }
}

//������������ջ���������ĺ���
Status initlstack(linkstack *s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

void push(linkstack *s,elemtype data)
{
    linkstackptr new = (linkstackptr)malloc(sizeof(stacknode));
    if(new == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    new->data = data;
    new->next = s->top;
    s->top = new;
    s->count++;
}

void pop(linkstack *s,elemtype *data)
{
    if(s->top == NULL)//ջ�գ���Ӧ�������û����룺1+= 
    {
        printf("\n���������ʽ����\n");
        printf("���л���Ӣ�ģ�ƥ������Ż��߲�Ҫ����ո�ȵ�\n");
        system("pause");
        exit(0);
    }
    else
    {
        linkstackptr temp;
        *data = s->top->data;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->count--;
    }
}

int main(void)
{
    //���ñ���
    int i = 0;//�����±�
    //��׺���ʽת����׺���ʽ�ı���
    LinkStack s;
    char c, d;//�������������
    char data[DATASIZE];//��ź�׺���ʽ
    //�����׺���ʽ�ı���
    linkstack s1;
    char str[MAXBUFFER];//�����������ڴ�������������
    elemtype n1, n2;//�������������
    int n = 0;//�������ڼ�����

    //��ʼ������ջ
    if(!initLStack(&s))
    {
        printf("��ʼ��ʧ��\n");
        system("pause");
        return -1;
    }
    if(!initlstack(&s1))
    {
        printf("��ʼ��ʧ��\n");
        system("pause");
        return -1;
    }

    //���潫��׺���ʽת��Ϊ��׺���ʽ����������data��
    printf("��������׺���ʽ����=��Ϊ������־(ֻ�ܽ�����������)��");
    scanf("%c", &c);
    while( c != '=' )
    {
        while(c>='0' && c<='9')//����ֱ�Ӵ�������
        {
            data[i] = c;
            i++;
            scanf("%c", &c);
            if(c<'0' || c>'9')//��������������
            {
                data[i] = ' ';
                i++;
            }
        }

        if(c == ')')
        {
            Pop(&s, &d);//��ջ
            while(d != '(')//���������žʹ�������
            {
                data[i] = d;
                i++;
                Pop(&s, &d);
            }
        }
        else if(c == '+' || c == '-')
        {
            if(!notEmptyLStack(&s))//�ǿ�����ջ
            {
                Push(&s, c);
            }
            else//����Ƚ�ջ��Ԫ��
            {
                do
                {
                    Pop(&s, &d);
                    if(d == '(')
                    {
                        Push(&s, d);
                    }
                    else//���������žʹ�������
                    {
                        data[i] = d;
                        i++;
                    }
                }while(notEmptyLStack(&s) && d != '(');
                //ֱ������������ȼ�����ջ�������
                Push(&s, c);//Ȼ������ջ
            }
        }
        else if(c == '(' || c == '*' || c == '/')
        {
            Push(&s, c);
        }
        else if(c == '=')
        {
            break;
        }
        else
        {
            printf("\n���������ʽ����\n");
            printf("���л���Ӣ�ģ�ƥ������Ż��߲�Ҫ����ո�ȵ�\n");
            system("pause");
            return -1;
        }

        scanf("%c", &c);
    }
    
    //������=ǰ�������,eg:1=
    if(!notEmptyLStack(&s))
    {
	    printf("\n���������ʽ����\n");
	    printf("���л���Ӣ�ģ�ƥ������Ż��߲�Ҫ����ո�ȵ�\n");
	    system("pause");
    	return -1;
	}

    while(notEmptyLStack(&s))//��ջ��ʣ������ŵ�����
    {
        
        Pop(&s, &data[i]);
        i++;
        data[i] = '=';
		data[i+1] = '\0';//�ַ���������־
    }    

    printf("\n��׺���ʽ��\n");
    printf("%s\n", data);
    
    //��������׺���ʽ
    for(i = 0; data[i] != '\0'; i++)
    {
        while(isdigit(data[i]))//��������
        {
            str[n++] = data[i];
            str[n] = '\0';
            if(n >= MAXBUFFER)
            {
                printf("����ĵ������ݹ���\n");
                system("pause");
                return -1;
            }
            i++;
            if(data[i] == ' ')
            {
                n1 = atoi(str);
                push(&s1, n1);
                n = 0;
                break;
            }
        }
        switch(data[i])
        {
            case '+':
            {
                pop(&s1, &n1);
                pop(&s1, &n2);
                push(&s1, n1 + n2);
                break;
            }
            case '-':
            {
                pop(&s1, &n1);
                pop(&s1, &n2);
                push(&s1, n2 - n1);
                break;
            }
            case '*':
            {
                pop(&s1, &n1);
                pop(&s1, &n2);
                push(&s1, n1 * n2);
                break;
            }
            case '/':
            {
                pop(&s1, &n1);
                pop(&s1, &n2);
                if(n1 != 0)
                push(&s1, n2 / n1);
                else
                {
                    printf("\n������������Ϊ��\n");
                    system("pause");
                    return -1;
                }
                break;
            }
        }
    }
    pop(&s1, &n1);
    printf("\n������Ϊ��%d\n\n", n1);
   
    system("pause");
    
    return 0;
}
