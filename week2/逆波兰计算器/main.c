#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

#define STACK_H_INCLUDED
#define DATASIZE 50//存放后缀表达式的数组长度
#define MAXBUFFER 10//最大缓冲区大小 

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

//函数的声明(链栈)
//栈内元素为字符型，用于处理输入的数据 
Status initLStack(LinkStack *s);//初始化栈
Status notEmptyLStack(LinkStack *s);//判断栈是否为空
void Push(LinkStack *s,ElemType data);//入栈
void Pop(LinkStack *s,ElemType *data);//出栈
//栈内元素为整型，用于处理输出的数据 
Status initlstack(linkstack *s);//初始化栈
void push(linkstack *s,elemtype data);//入栈
void pop(linkstack *s,elemtype *data);//出栈

//下面是字符型链栈基本操作的函数 
Status initLStack(LinkStack *s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

Status notEmptyLStack(LinkStack *s)
{
    if(s->top != NULL)//非空返回1
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
        printf("内存分配失败\n");
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
        printf("栈空\n");
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

//下面是整型链栈基本操作的函数
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
        printf("内存分配失败\n");
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
    if(s->top == NULL)//栈空，对应错误：如用户输入：1+= 
    {
        printf("\n出错：输入格式错误！\n");
        printf("请切换成英文，匹配好括号或者不要输入空格等等\n");
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
    //共用变量
    int i = 0;//数组下标
    //中缀表达式转换后缀表达式的变量
    LinkStack s;
    char c, d;//处理输入的数据
    char data[DATASIZE];//存放后缀表达式
    //计算后缀表达式的变量
    linkstack s1;
    char str[MAXBUFFER];//缓冲区，用于处理连续的数字
    elemtype n1, n2;//处理输出的数据
    int n = 0;//缓冲区内计数器

    //初始化两个栈
    if(!initLStack(&s))
    {
        printf("初始化失败\n");
        system("pause");
        return -1;
    }
    if(!initlstack(&s1))
    {
        printf("初始化失败\n");
        system("pause");
        return -1;
    }

    //下面将中缀表达式转换为后缀表达式储存在数组data中
    printf("请输入中缀表达式，以=作为结束标志(只能进行整数运算)：");
    scanf("%c", &c);
    while( c != '=' )
    {
        while(c>='0' && c<='9')//整数直接存入数组
        {
            data[i] = c;
            i++;
            scanf("%c", &c);
            if(c<'0' || c>'9')//处理连续的数字
            {
                data[i] = ' ';
                i++;
            }
        }

        if(c == ')')
        {
            Pop(&s, &d);//出栈
            while(d != '(')//不是左括号就存入数组
            {
                data[i] = d;
                i++;
                Pop(&s, &d);
            }
        }
        else if(c == '+' || c == '-')
        {
            if(!notEmptyLStack(&s))//非空则入栈
            {
                Push(&s, c);
            }
            else//否则比较栈顶元素
            {
                do
                {
                    Pop(&s, &d);
                    if(d == '(')
                    {
                        Push(&s, d);
                    }
                    else//不是左括号就存入数组
                    {
                        data[i] = d;
                        i++;
                    }
                }while(notEmptyLStack(&s) && d != '(');
                //直到该运算符优先级大于栈顶运算符
                Push(&s, c);//然后再入栈
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
            printf("\n出错：输入格式错误！\n");
            printf("请切换成英文，匹配好括号或者不要输入空格等等\n");
            system("pause");
            return -1;
        }

        scanf("%c", &c);
    }
    
    //检查如果=前无运算符,eg:1=
    if(!notEmptyLStack(&s))
    {
	    printf("\n出错：输入格式错误！\n");
	    printf("请切换成英文，匹配好括号或者不要输入空格等等\n");
	    system("pause");
    	return -1;
	}

    while(notEmptyLStack(&s))//将栈内剩余对象存放到数组
    {
        
        Pop(&s, &data[i]);
        i++;
        data[i] = '=';
		data[i+1] = '\0';//字符串结束标志
    }    

    printf("\n后缀表达式：\n");
    printf("%s\n", data);
    
    //下面计算后缀表达式
    for(i = 0; data[i] != '\0'; i++)
    {
        while(isdigit(data[i]))//过滤数字
        {
            str[n++] = data[i];
            str[n] = '\0';
            if(n >= MAXBUFFER)
            {
                printf("输入的单个数据过大\n");
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
                    printf("\n出错：除数不能为零\n");
                    system("pause");
                    return -1;
                }
                break;
            }
        }
    }
    pop(&s1, &n1);
    printf("\n计算结果为：%d\n\n", n1);
   
    system("pause");
    
    return 0;
}
