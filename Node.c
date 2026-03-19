#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define Maxsize 100
//链表节点结构体
typedef struct node
{
    ElemType data;
    struct node *next;
}Node;
//链表初始化(创建头结点)
Node *InitList(void)
{
    Node *head=(Node *)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
//链表头插法
void Node_HeadInsert(Node*Head,ElemType e)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=Head->next;
    Head->next=p;
}
//遍历链表
void Node_printf(Node *Head)
{
    Node *p=Head->next;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
//找到尾节点
Node *Node_FindTail(Node *Head)
{
    Node *p=Head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}
//链表尾插法
void Node_TailInsert(Node *Tail,ElemType e)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=e;
    Tail->next=p;
    p->next=NULL;
}
//在指定位置插入元素
void Node_Insert(Node *Head,int pos,ElemType e)
{
    Node *p=Head;
    int i=0;
    //找到要插入的前一个位置
    while(i<pos-1 && p->next!=NULL)
    {
        p=p->next;
        i++;
    }
    Node *q=(Node *)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
}
//删除节点
void Node_Delete(Node *Head,int pos)
{
    Node *p=Head;
    int i=0;
    while(i<pos-1 &&p->next !=NULL)
    {
        p=p->next;
        i++;
    }
    Node *q=p->next;//用q记录下要删除的节点
    p->next=q->next;
    free(q);
}
//测试函数
int main()
{
    Node*Head=InitList();
    Node_HeadInsert(Head,1);
    Node_HeadInsert(Head,2);
    Node_HeadInsert(Head,3);
    Node *Tail=Node_FindTail(Head);
    Node_TailInsert(Tail,4);
    Node_Insert(Head,2,5);
    Node_Delete(Head,3);
    Node_printf(Head);
}
