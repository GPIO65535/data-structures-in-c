#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MaxSize 100
//顺序表结构体
typedef struct
{
    ElemType *data;
    int length;
}SeqList;
//顺序表初始化
SeqList *SeqList_Init(void)
{
    SeqList*L=(SeqList*)malloc(sizeof(SeqList));
    L->data=(ElemType*)malloc(MaxSize*sizeof(ElemType));
    L->length=0;
    return L;
}
//向顺序表尾部添加元素
int SeqList_Append(SeqList *L,ElemType e)
{
    if(L->length>=MaxSize)
    {
        printf("顺序表已满,无法再插入!\n");
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
    return 1;
}
//指定位置插入元素
int SeqList_Insert(SeqList *L,int pos,ElemType e)
{
    if(pos<1||pos>L->length+1)
    {
        printf("插入位置不合法!\n");
        return 0;
    }
    if(L->length>=MaxSize)
    {
        printf("顺序表已满,无法再插入!\n");
        return 0;
    }
    for(int i=L->length-1;i>=pos-1;i--)
    {
        L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=e;
    L->length++;
    return 1;
}
//指定位置删除元素
int SeqList_Delete(SeqList *L,int pos)
{
    if(pos<1||pos>L->length)
    {
        printf("删除位置不合法!\n");
        return 0;
    }
    for(int i=pos-1;i<L->length-1;i++)
    {
        L->data[i]=L->data[i+1];
    }
    L->length--;
    return 1;
}
//顺序表查找元素
int SeqList_Search(SeqList *L,ElemType e)
{
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}
//打印顺序表
void SeqList_Print(SeqList *L)
{
    for(int i=0;i<L->length;i++)
    {
        printf("%d\n",L->data[i]);
    }
}
int main()
{
    SeqList *L=SeqList_Init();
    SeqList_Append(L,1);
    SeqList_Append(L,2);
    SeqList_Insert(L,2,3);
    SeqList_Print(L);
}