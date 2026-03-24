#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define Maxsize 100
//双向链表节点结构体
typedef struct node
{
    ElemType data;
    struct node *prev,*next;
}Node;
//双向链表初始化(创建头结点)
Node *Node_Init(void)
{
    Node *head=(Node *)malloc(sizeof(Node));
    head->prev=NULL;
    head->next=NULL;
    head->data=0;
    return head;
}
//头插法
void Node_HeadInsert(Node *Head,ElemType e)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=e;
    p->prev=Head;
    p->next=Head->next;
    if(Head->next!=NULL)
    {
         Head->next->prev=p;
    }   
    Head->next=p;
}
void Node_printf(Node *head)
{
    Node *p=head->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//在指定位置插入元素
void Node_Insert(Node*Head,ElemType e, int pos)
{
    Node *p=Head;
    Node *q=(Node *)malloc(sizeof(Node));
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    q->data=e;
    q->prev=p;
    q->next=p->next;
    if(p->next!=NULL)
    {
        p->next->prev=q;
    }
    p->next=q;
}
//删除节点
void Node_Delete(Node *Head,int pos)
{
    Node *p=Head;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    //要删除的节点
    Node *q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
}
//测试函数
int main()
{
    Node *head=Node_Init();
    Node_HeadInsert(head,1);
    Node_HeadInsert(head,2);
    Node_HeadInsert(head,3);
    Node_HeadInsert(head,4);
    Node_HeadInsert(head,5);
    Node_Insert(head,2,3);
    Node_Delete(head,3);
    Node_printf(head);
    return 0;
}
