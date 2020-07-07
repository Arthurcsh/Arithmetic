//
//  LRUCache.h
//  FISample
//
//  Created by chengshaohua on 2020/5/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef LRUCache_h
#define LRUCache_h

#include <stdio.h>

typedef struct LRUNode {
    int key;
    int value;
    struct LRUNode *prev;
    struct LRUNode *next;
}LRUNode;

typedef struct LRUCache {
    int capacity;   // LRU最大缓存数
    int size;       // LRU缓存数数
    LRUNode *head;  // 链表指向上节点
    LRUNode *tail;  // 链表指向下节点
//    HashMap *hashmap; // 缓存字典
}LRUCache;


#endif /* LRUCache_h */
