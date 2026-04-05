#include<stdio.h>
#include<stdlib.h>
typedef char Elemtype;
typedef struct TreeNode
{
    Elemtype data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}Tree;
//二叉树初始化:创建一个带头结点的空二叉树
void Tree_Init(Tree*T)
{
    T=(Tree*)malloc(sizeof(Tree));
    T->lchild=NULL;
    T->rchild=NULL;
}
Tree* Tree_Create(Tree*T,Elemtype x,Tree*lbt,Tree*rbt)
{
    T=(Tree*)malloc(sizeof(Tree));
    T->data=x;
    T->lchild=lbt;
    T->rchild=rbt;
    return T;
}
//二叉树的左插入:将数据元素x插入到二叉树bt中的parent所指结点的左孩子处
Tree*Tree_InsertL(Tree*bt,Elemtype x,Tree*parent)
{
    Tree *p=(Tree*)malloc(sizeof(Tree));
    if (p==NULL)
    {
        return NULL;
    }
    p->data=x;
    if(parent->lchild==NULL)
    {
        parent->lchild=p;
    }
    else
    {
        p->lchild=parent->lchild;
        parent->lchild=p;
    }
    return bt;
}
//二叉树的左删除:删除二叉树bt中parent所指结点的左子树
Tree *Tree_DeleteL(Tree*bt,Tree*parent)
{
    if(parent->lchild==NULL)
    {
        return NULL;
    }
    Tree *p=parent->lchild;
    parent->lchild=NULL;
    free(p);
    return bt;
}
//二叉树的查找:在二叉树bt中查找数据元素x
Tree*Tree_Find(Tree*bt,Elemtype x)
{
    Tree *p;
    if(bt==NULL)
    {
        return NULL;
    }
    if(bt->data==x)
    {
        return bt;
    }
    if(bt->lchild!=NULL)
    {
        p=Tree_Find(bt->lchild,x);
        if(p!=NULL)
        {
            return p;
        }
    }
    if(bt->rchild!=NULL)
    {
        p=Tree_Find(bt->rchild,x);
        if(p!=NULL)
        {
            return p;
        }
    }
}
//统计x在二叉树bt中出现的次数
int Tree_Count(Tree*bt,Elemtype x)
{
    static int count=0;
    if(bt==NULL)
    {
        return 0;
    }
    if(bt->data==x)
    {
        count++;
    }
    if(bt->lchild!=NULL)
    {
        Tree_Count(bt->lchild,x);
    }
    if(bt->rchild!=NULL)
    {
        Tree_Count(bt->rchild,x);
    }
    return count;
}
//统计二叉树bt中叶子结点的个数
int Tree_CountLeaf(Tree*bt)
{
    static int count=0;
    if(bt==NULL)
    {
        return 0;
    }
    if(bt->lchild==NULL && bt->rchild==NULL)
    {
        count++;
    }
    if(bt->lchild!=NULL)
    {
        Tree_CountLeaf(bt->lchild);
    }
    if(bt->rchild!=NULL)
    {
        Tree_CountLeaf(bt->rchild);
    }
    return count;
}
//统计度为2的节点的个数
int Tree_CountDegree2(Tree*bt)
{
    static int count=0;
    if(bt==NULL)
    {
        return 0;
    }
    if(bt->lchild!=NULL && bt->rchild!=NULL)
    {
        count++;
    }
    if(bt->lchild!=NULL)
    {
        Tree_CountDegree2(bt->lchild);
    }
    if(bt->rchild!=NULL)
    {
        Tree_CountDegree2(bt->rchild);
    }
    return count;
}

//找到二叉树中度为1的节点
int Tree_CountDegree1(Tree *bt)
{
    static int count=0;
    if(bt==NULL)
    {
        return 0;
    }
    if (bt->lchild!=NULL &&bt ->rchild==NULL || bt->lchild==NULL &&bt->rchild!=NULL)
    {
        count++;
    }
    if(bt->lchild!=NULL)
    {
        Tree_CountDegree1(bt->lchild);
    }
    if(bt->rchild!=NULL)
    {
        Tree_CountDegree1(bt->rchild);
    }
    return count;
}