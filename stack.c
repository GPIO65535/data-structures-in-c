#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define Maxsize 100
//栈结构
typedef struct
{
    ElemType data[Maxsize];
    int top;
}Stack;
//栈初始化
void Stack_Init(Stack*s)
{
    s->top=-1;
}
//判断栈是否为空
int Stack_Empty(Stack *s)
{
    if(s->top==-1)
    {
        printf("栈为空!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
//入栈
int Stack_Push(Stack *s,ElemType e)
{
    if(s->top>=Maxsize-1)
    {
        printf("栈已满!\n");
        return 1;
    }
    s->top++;
    s->data[s->top]=e;
    return 0;
}
//出栈
int Stack_Pop(Stack *s,ElemType *e)
{
    if(s->top==-1)
    {
        printf("栈为空!\n");
        return 1;
    }
    *e=s->data[s->top];
    s->top--;
    return 0;
}