#include<stdio.h>
#include<stdlib.h>
typedef char Elemtype;
typedef struct TreeNode
{
    Elemtype data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}Tree;
//创建二叉树
char str[]="ABDH#K###E##CFI###G#J##";
int indx=0;
void CreateTree(Tree **T)
{
    char ch=str[indx++];
    if(ch=='#')
    {
        *T=NULL;
    }
    else
    {
        *T=(Tree*)malloc(sizeof(Tree));
        (*T)->data=ch;
        CreateTree(&(*T)->lchild);
        CreateTree(&(*T)->rchild);
    }
}
//前序遍历
void PreOrder(Tree *T)
{
    if(T!=NULL)
    {
        printf("%c ",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(Tree*T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        printf("%c ",T->data);
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(Tree *T)
{
    if(T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ",T->data);
    }
}
//测试
int main(void)
{
    Tree *T;
    CreateTree(&T);
    printf("前序遍历:");
    PreOrder(T);
    printf("\n");
    printf("中序遍历:");
    InOrder(T);
    printf("\n");
    printf("后序遍历:");
    PostOrder(T);
    printf("\n");
    return 0;
}