//
//  FIBiTree.c
//  FISample
//
//  Created by chengshaohua on 2017/11/30.
//  Copyright © 2017年 www.bundwealth.com. All rights reserved.
//

#include "FIBiTree.h"
#include "stdio.h"
#include "stdlib.h"
//#include"conio.h"

#define ElemType char


BiTree CreateBiTree() { 
    char data;
    BiTree T;
    scanf("%c",&data);
    //  getchar();
    if(data=='#') T=NULL;         /*这里的输入要严格按照正确的顺序才能结束.这里要用到二叉树的一个性质,就是说对于有n个节点的二叉树,就有n+1个空域,在这里即为如果你输入了n个元素,那么一定要有n+1个#才会结束迭代过程.*/
    else                        /*例如1234#####才能成功！*/
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = data;
        T->Lchild = CreateBiTree();
        T->Rchild = CreateBiTree();
        if(T->data != '#') {
            printf("---  %c\n",T->data);
        }
    }
    return T;  //return root node
}

void Visit(BiTree T) {
    if(T->data != '#'){
        printf("Visit  %c ",T->data);
    }
}
//先序遍历二叉树
void PreOrderTraverse(BiTree T) {
    if(T) {
        Visit(T);
        PreOrderTraverse(T->Lchild);
        PreOrderTraverse(T->Rchild);
    }
}
//中序遍历二叉树
void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->Lchild);
        printf("%c",T->data);
        InOrderTraverse(T->Rchild);
    }
}
//后序遍历二叉树
void PostOrderTraverse(BiTree T) {
    if(T) {
        PostOrderTraverse(T->Lchild);
        PostOrderTraverse(T->Rchild);
        printf("%c",T->data);
    }
}
