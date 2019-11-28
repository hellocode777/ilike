#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void PreOrderTraverse(BiTree T)//二叉树的先序遍历
{
    if(T==NULL)
        return ;
    printf("%c ",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BiTree T)//二叉树的中序遍历
{
   if(T==NULL)
       return ;
   InOrderTraverse(T->lchild);
    printf("%C ",T->data);
    InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree T)//后序遍历
{
    if(T==NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ",T->data);
}
void CreateBiTree(BiTree *T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        *T=NULL;
    else
    {
        *T=(BiTree  )malloc(sizeof(BiTNode));
        if(!*T)
            exit(-1);
        (*T)->data=ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void pri(){
    printf("\n");
}

int main()
{
    BiTree T;
    printf("输入树(#代表空节点 AB#C##D##):");
    CreateBiTree(&T);
    printf("前序遍历的结果是:");
    PreOrderTraverse (T);
    printf("\n中序遍历的结果是:");
    InOrderTraverse(T);
    printf("\n后序遍历的结果是:");
    PostOrderTraverse(T);
    pri();
    return 0;
}
