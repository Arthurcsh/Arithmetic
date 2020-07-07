//
//  HashMap.h
//  FISample
//
//  Created by chengshaohua on 2020/5/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef HashMap_h
#define HashMap_h

#include <stdio.h>

typedef struct {
    int key;         // 键
    int value;       // 值
}DataType;

typedef struct HashNode {
    DataType data;
    struct HashNode *next; // 冲突链表
}HashNode;

typedef struct {
    int size;
    HashNode *table;  // 哈希列表
}HashMap, *hashmap;

#endif /* HashMap_h */
