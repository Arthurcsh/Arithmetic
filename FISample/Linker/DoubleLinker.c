//
//  DoubleLinker.c
//  FISample
//
//  Created by chengshaohua on 2020/5/18.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "DoubleLinker.h"
#include "stdlib.h"

/**
 * 创建表头表示的双向链表：头指针和尾指针都指向自身
 */
LPDNode initDoubleLinker() {
    LPDNode headNode = (LPDNode)malloc(sizeof(DNode));
    headNode->front = headNode->tail = headNode;
    
    return headNode;
}

/**
 * 创建插入的双向链表节点: 头指针和尾指针初始都是NULL
 * C语言：堆内存申请：malloc + free
 * C++: new + delete
 */
LPDNode createLinkerNode(DLElemType element) {
    LPDNode newNode = (LPDNode)malloc(sizeof(DNode));
    newNode->data = element;
    newNode->front = newNode->tail = NULL;
    
    return newNode;
}

/**
 * 表头插入法
 */
void insertNodeWithHead(LPDNode head, DLElemType data) {
    LPDNode newNode = createLinkerNode(data);
    
    if (head->tail == NULL) {
        head->tail = newNode;
        newNode->front = head;
        return;
    }
    
    // 对于head->tail前插入newNode，注意：先连后断
    newNode->tail = head->tail;
    newNode->front = head;
    head->tail->front = newNode;
    head->tail = newNode;
}

/**
* 表尾插入法
*/
void insertNodeWithTail(LPDNode head, DLElemType data) {
    
}

/**
 * 遍历输出
 */
void printLinker(LPDNode head) {
    LPDNode pmove = head->tail;
    
    // while (pmove->tail != head) 最后一个节点不打印
    while (pmove != head) {
        printf("%d", pmove->data);
        pmove = pmove->tail;
    }
    printf("\n");
}
