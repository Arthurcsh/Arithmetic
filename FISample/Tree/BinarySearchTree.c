//
//  BinarySearchTree.c
//  FISample
//
//  Created by chengshaohua on 2020/5/14.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "BinarySearchTree.h"
#include <stdlib.h>
#include "string.h"

// 二叉搜索树数据封装：数据需要关键字
typedef struct data {
    int first;        // 关键字
    char second[20];  // 数据
} DATA, *LPDATA;

// 二叉树节点
typedef struct binaryTreeNode {
    DATA element;
    struct binaryTreeNode *LChild;
    struct binaryTreeNode *RChild;
}NODE, *LPNODE;

typedef struct binarySearchTree {
    struct binaryTreeNode *root;   // 二叉树：根节点表示整棵树
    int treeSize;  // 万金油参数
}BTREE, *LPBTREE;

// 插入节点
LPNODE createNode(DATA element) {
    // 创建一个节点：创建一个结构体变量
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->element = element;
    newNode->LChild = NULL;
    newNode->RChild = NULL;
    
    return newNode;
}

// 创建一个二叉搜索树，描述最初的状态
LPBTREE createBinarySearchTree() {
    LPBTREE tree = (LPBTREE)malloc(sizeof(BTREE));
    tree->root = NULL;
    tree->treeSize = 0;
    return tree;
}

int size(LPBTREE tree) {
    return tree->treeSize;
}

int empty(LPBTREE tree) {
    return (tree->treeSize == 0) ? 1 : 0;
}

// 插入节点
void insertNode(LPBTREE tree, DATA element) {
    LPNODE moveNode = tree->root;
    LPNODE moveParent = NULL;
    while (moveNode != NULL) {
        // 记录当前位置在移动
        moveParent = moveNode;
        // 移动：根据关键字移动
        if (element.first < moveNode->element.first) {
            moveNode = moveNode->LChild;
        }else if (element.first > moveNode->element.first) {
            moveNode = moveNode->RChild;
        }else {
            strcpy(moveNode->element.second, element.second);
            return;
        }
        
        // 退出循环表示找到插入位置
        // 创建插入节点
        LPNODE node = createNode(element);
        if (element.first < moveParent->element.first) {
            moveParent->LChild = node;
        }else {
            moveParent->RChild = node;
        }
    }
}

void printTree(LPNODE node) {
    if (node != NULL) {
        printTree(node->LChild);
        printf("-- %d\t %s\n", node->element.first, node->element.second);
        printTree(node->RChild);
    }
}

void printSearchTree(LPBTREE tree) {
    printTree(tree->root);
}
