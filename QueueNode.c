#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef struct queuenode
{
    ElemType data;
    struct queuenode *next;
}QueueNode;
typedef struct
{
    QueueNode *front;
    QueueNode *rear;
}q;
QueueNode *QueueNode_Init(void)
{
    QueueNode *p=(QueueNode*)malloc(sizeof(QueueNode));
    p->data=0;
    p->next=NULL;
    q*qu=(q*)malloc(sizeof(q));
    qu->front=p;
    qu->rear=p;
    return p;
}
//把头节点当成队头，进行入队(尾插法)
void Que_In(q *qu,ElemType e)
{
    QueueNode *p=(QueueNode *)malloc(sizeof(QueueNode));
    p->data=e;
    p->next=NULL;
    qu->rear->next=p;
    qu->rear=p;
}
//出队(删除头节点后的第一个节点)
void Que_Out(q*qu,ElemType *e)
{
    QueueNode *p=qu->front->next;
    *e=p->data;
    qu->front->next=p->next;
    if(qu->rear==p)
    {
        qu->rear=qu->front;
    }
    free(p);
}
//测试
int main(void)
{
    q *qu=(q*)malloc(sizeof(q));
    qu->front=QueueNode_Init();
    qu->rear=qu->front;
    ElemType e;
    Que_In(qu,1);
    Que_In(qu,2);
    Que_In(qu,3);
    Que_Out(qu,&e);
    printf("出队元素:%d\n",e);
    QueueNode *p=qu->front->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}