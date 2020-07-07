//
//  FILinker.c
//  FISample
//
//  Created by chengshaohua on 2017/12/8.
//  Copyright © 2017年 www.bundwealth.com. All rights reserved.
//

#include "FILinker.h"
#include "stdlib.h"



// 创建一个节点
Q1LinkNode *createQ1LinkNode(int data) {
    Q1LinkNode *node = (Q1LinkNode *)malloc(sizeof(Q1LinkNode));
    node->data = data;
    node->link = 0;
    return node;
}

// 添加一个节点
Q1LinkNode *addQ1Node(Q1LinkNode **heaad , int data) {
    unsigned long l = 0, prior = 0;
    Q1LinkNode *p = *heaad;
    while (1) {
        prior = p->link ^l;
        if (prior == 0) {
            Q1LinkNode *node = createQ1LinkNode(data);
            p->link = l ^ (unsigned long)node;
            
            l = (unsigned long)p;
            node->link = l ^ 0;
            return node;
        }
        l = (unsigned long)p;
        p = (Q1LinkNode *)prior;
        
    }
}

// 打印节点
void printQ1Node(Q1LinkNode *head) {
    unsigned long l = 0 , prior = 0;
    Q1LinkNode *p = head;
    printf("%d ",p->data);
    while (1) {
        prior = p->link ^ l;
        if (prior == 0) {
            break;
        }
        l = (unsigned long)p;
        p = (Q1LinkNode *)prior;
        printf("%d ",p->data);
    }
}
