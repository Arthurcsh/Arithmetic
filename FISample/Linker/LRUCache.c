//
//  LRUCache.c
//  FISample
//
//  Created by chengshaohua on 2020/5/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "LRUCache.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 *  维护一个有序单链表，越靠近链表尾部的结点是越早之前访问的。
 *  当有一个新的数据被访问时，我们从链表头开始顺序遍历链表。
 * 1. 如果此数据之前已经被缓存在链表中了，遍历得到这个数据对应的结点，并将其从原来的位置删除，
 *    然后再插入到链表的头部。
 * 2. 如果此数据没有在缓存链表中，
 *    又可以分为两种情况：如果此时缓存未满，则将此结点直接插入到链表的头部；
 *    如果此时缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部
 *
 *  需要遍历一遍链表，所以这种基于链表的实现思路，缓存访问的时间复杂度为 O(n)
 *  可以继续优化这个实现思路，比如引入散列表（Hash table）来记录每个数据的位置，将缓存访问的时间复杂度降到 O(1)。因为要涉及我们还没有讲到的数据结构，所以这个优化方案
 */

/**
 * 创建双向链表节点
 */
LRUNode* createLRUNode(int key, int value) {
    LRUNode *node = (LRUNode*)malloc(sizeof(LRUNode));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int chacheSize() {
    
    return 0;
}

/**
 * 头插法插入新节点
 */
LRUNode* addLRUNodeFirst(LRUNode* head, int key, int value) {
    if (head == NULL) return head;
    
    LRUNode *newNode = createLRUNode(key, value);
    LRUNode *next = head->next;
    head->next->prev = newNode;
    newNode->prev = head;
    newNode->next = next;
    head->next = newNode;
    return head;
}

void removeLRUNode(int value) {
    
}

void removeLastNode() {
    
}
