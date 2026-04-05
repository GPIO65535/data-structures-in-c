#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}Tree;
int TreeArr[]={70,55,49,30,-1,39,-1,-1,53,-1,-1,-1,80,75,-1,-1,98,95,-1,-1,-1};
//线性查找
int linear_find(int *arr,int len,int key)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
//二分查找
int binary_find(int *arr,int len,int key)
{
    int low=0;
    int high=len-1;
    int mid=(low+high)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
    return -1;
}
//二叉排序树
int indx=0;
//二叉排序树的创建
Tree *CreateTree(Tree **T)
{
    ElemType num=TreeArr[indx++];
    if(num==-1)
    {
        *T=NULL;
    }
    else
    {
        *T=(Tree *)malloc(sizeof(Tree));
        (*T)->data=num;
        (*T)->lchild=NULL;
        (*T)->rchild=NULL;
        CreateTree(&(*T)->lchild);
        CreateTree(&(*T)->rchild);
    }
    return *T;
}
//前序遍历
void PreOrder(Tree *T)
{
    if (T!=NULL)
    {
        printf("%d ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    
}
//二叉排序树的查找
int Search(Tree *T,ElemType key,Tree **pos)
{
    if(T==NULL)
    {
        return 0;
    }
    else if(T->data==key)
    {
        *pos=T;
        return 1;
    }
    else if(T->data>key)//要查的值小，往左子树找
    {
        return Search(T->lchild,key,pos);
    }
    else//要查的值大，往右子树找
    {
        return Search(T->rchild,key,pos);
    }
}
// 二叉排序树的插入
int Insert(Tree **T, ElemType key)
{
    // 1. 如果当前节点为空，说明找到了插入位置，创建新节点
    if (*T == NULL)
    {
        *T = (Tree *)malloc(sizeof(Tree));
        (*T)->data = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        return 1; // 插入成功
    }
    // 2. 如果存在相同关键字，则不再插入
    else if ((*T)->data == key)
    {
        return 0; // 插入失败
    }
    // 3. 要插入的值较小，继续去左子树进行递归插入
    else if ((*T)->data > key)
    {
        return Insert(&((*T)->lchild), key);
    }
    // 4. 要插入的值较大，继续去右子树进行递归插入
    else
    {
        return Insert(&((*T)->rchild), key);
    }
}
//main函数测试
int main()
{
    Tree *T;
    CreateTree(&T);
    printf("前序遍历:");
    PreOrder(T);
    printf("\n");
    Tree *pos;
    Search(T,53,&pos);
    printf("查找结果:%d\n",pos->data);
    Insert(&T,60);
    printf("插入60后的前序遍历:");
    PreOrder(T);
    printf("\n");
    return 0;
}