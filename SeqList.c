#include"stdio.h"
typedef int ElemType;
#define MaxSize 100
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SeqList;
void SeqList_Init(SeqList *L)
{
    L->length=0;
}
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
int main()
{
    SeqList L;
    SeqList_Init(&L);
    SeqList_Append(&L,1);
    SeqList_Append(&L,2);
    SeqList_Append(&L,3);
    printf("%d\n",L.data[0]);
    printf("%d\n",L.data[1]);
    printf("%d\n",L.data[2]);
    return 0;
}