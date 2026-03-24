#include<stdio.h>
typedef int ElemType;
#define MAXSIZE 100
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Que;
void Que_Init(Que *q)
{
    q->front=0;
    q->rear=0;
}
int Que_Empty(Que *q)
{
    if(q->front==q->rear)
    {
        printf("队列为空!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int Que_Out(Que*q,ElemType *e)
{
    if(q->front==q->rear)
    {
        printf("队列为空!\n");
        return 1;
    }
    *e=q->data[q->front];
    q->front++;
    return 0;
}
int Que_In(Que*q,ElemType e)
{
    if(q->rear>=MAXSIZE)
    {
        printf("队列已满!\n");
        return 1;
    }
    q->data[q->rear]=e;
    q->rear++;
    return 0;
}
int main(void)
{
    Que q;
    ElemType e;
    Que_Init(&q);
    Que_In(&q,1);
    Que_In(&q,2);
    Que_In(&q,3);
    Que_Out(&q,&e);
    printf("出队元素:%d\n",e);
    for(int i=q.front;i<q.rear;i++)
    {
        printf("%d ",q.data[i]);
    }
}