//
//  BinaryTree.c
//  FISample
//
//  Created by chengshaohua on 2020/5/3.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "BinaryTree.h"
#include <stdlib.h>
#include <math.h>

/**
 * 创建二叉树
 */
TreeNode* createTreeNode(char data) {
    TreeNode *treeNode = (TreeNode*)malloc(sizeof(TreeNode));
    treeNode->data = data;
    treeNode->lnode = NULL;
    treeNode->rnode = NULL;
    
    return treeNode;
}

/**
 * 连接二叉树节点
 */
void insertTreeNode(TreeNode *treeNode, TreeNode *leftNode, TreeNode *rightNode) {
    treeNode->lnode = leftNode;
    treeNode->rnode = rightNode;
}

// 节点打印
void printNodeData(TreeNode *treeNode) {
    printf("%c\t", treeNode->data);
}

/**
 * 递归遍历(中序遍历)
 */
void midOrderTree(TreeNode *treeNode) {
    if (treeNode != NULL) {
        midOrderTree(treeNode->lnode);
        printNodeData(treeNode);
        midOrderTree(treeNode->rnode);
    }
}

/**
 * 非递归方式， DFS深度优先搜索
 */
void midOrderWithStack(TreeNode *tree) {
    if (tree == NULL) return;
    
    TreeNode *stack[10];
    int stackTop = -1;        // 入栈顶元素
    TreeNode *pMove = tree;   // 移动指针
    
    while (stackTop != -1 || pMove) {
        // 找最左边，一直到底
        while (pMove) {
//            printf("%c\t", pMove->data);  // 先序遍历
            stack[++stackTop] = pMove;
            pMove = pMove->lnode;
        }
        
        // 移动指针==NULL, 没有左边， 去找右边
        // 出栈
        if (stackTop != -1) {
            // 获取pmove父节点
            pMove = stack[stackTop--];  // 栈顶元素
            printf("%c\t", pMove->data);
            pMove = pMove->rnode;
        }
    }
}

/**
 * 后序遍历非递归
 * 双栈法
 */
void postOrderWithStack(TreeNode *tree) {
    TreeNode *stack[20], *output[20];
    int stackTop = -1, outputTop = -1;
    
    TreeNode *pMove = tree;   // 树根节点
    while (pMove != NULL || stackTop != -1) {
        if (pMove != NULL) {
            stack[++stackTop] = pMove;
            output[++outputTop] = pMove;  // 先output入栈父节点
            pMove = pMove->rnode;         // 继续遍历右孩子
        } else {                          // 右孩子访问完成后，切换到左孩子
            pMove = stack[stackTop--];    // 通过回溯记录的父节点出栈
            pMove = pMove->lnode;         // 继续遍历左孩子
        }
    }
    
    // output入栈顺序： [父节点-右孩子-左孩子]
    while (outputTop != -1) {
        // 出栈顺序： [左孩子-右孩子-父节点], 即后序遍历
        TreeNode *node = output[outputTop--];
        printf("%c\t", node->data);
    }
    printf("\n");
}

// 二叉树的节点数
int binaryTreeNodeCount(TreeNode *tree) {
    if (tree == NULL) return 0;
    
    return 1 + binaryTreeNodeCount(tree->lnode) + binaryTreeNodeCount(tree->rnode);
}

// 满二叉树节点树与高度关系
int treeNodeCount(TreeNode *tree) {
    int h = 0;
    // 计算树的高度
    while (tree != NULL) {
        tree = tree->lnode;
        h++;
    }
    // 节点总数 2^h - 1
    return (int)pow(2,h) - 1;
}

/**
 * 中序遍历二叉树(递归&非递归)
 */
TreeNode* midOrderTreeNode() {
    TreeNode *A = createTreeNode('A');
    TreeNode *B = createTreeNode('B');
    TreeNode *C = createTreeNode('C');
    TreeNode *D = createTreeNode('D');
    TreeNode *E = createTreeNode('E');
    TreeNode *F = createTreeNode('F');
    TreeNode *G = createTreeNode('G');
    TreeNode *H = createTreeNode('H');
    
    insertTreeNode(A, B, C);
    insertTreeNode(B, D, E);
    insertTreeNode(C, F, G);
    insertTreeNode(F, NULL, H);
    
    int count = binaryTreeNodeCount(A);
    printf("tree node count: %d\n", count);
    
    midOrderTree(A);
    printf("\n");
    midOrderWithStack(A);
    printf("\n");
    
    return A;
}

/**
 * 中序遍历-非递归(双栈法)
 */
TreeNode* postOrderTreeNode() {
    TreeNode *A = createTreeNode('A');
    TreeNode *B = createTreeNode('B');
    TreeNode *C = createTreeNode('C');
    TreeNode *D = createTreeNode('D');
    TreeNode *E = createTreeNode('E');
    TreeNode *F = createTreeNode('F');
    TreeNode *G = createTreeNode('G');
    TreeNode *H = createTreeNode('H');
    
    insertTreeNode(A, B, C);
    insertTreeNode(B, D, E);
    insertTreeNode(C, F, G);
    insertTreeNode(F, NULL, H);
    
    postOrderWithStack(A);
    
    return A;
}

/**
 * 红黑树定义：
 * 1. 树节点是红色或黑色，根节点和叶子节点都是黑色，其中叶节点为Null节点
 * 2. 每个红色节点的子节点是黑色 (所有叶子到根的路径不能有两个连续的红色节点)
 * 3. 从任意节点到每个叶子的简单路径包含相同的黑色节点 (高黑)
 * 4. 确保任意节点到每个叶子节点路径不会超过最短路径的2倍
 */

/**
 * BFS广度优先搜索
void LevelOrderTraversal(TreeNode BT) {
    TreeNode T;
    Queue Q;    //声明一个队列
    if (BT == NULL)
        return;                 //如果树为空，直接返回
    Q = CreatQueue(MAX_SIZE);   //创建并初始化队列
    AddQ(Q, BT);                //将 根节点入队
    while (!IsEmpty(Q)) {
        T = DeleteQ(Q);    　　　　　　　　　　//节点出队
        printf("%d\n", T->Data);    　　　　 //访问出队的节点
        if (T->Left)    AddQ(Q, T->Left);   //若左儿子不为空，将其入队
        if (T->Right)    AddQ(Q, T->Right)  //若右儿子不为空，将其入队
    }
}
*/


