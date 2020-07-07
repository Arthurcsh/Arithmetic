//
//  HashTable.h
//  FISample
//
//  Created by chengshaohua on 2020/5/31.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>

#define key_size 100;
#define hash_size 100;

typedef struct htItem {
    uint fid;   // 记录值
    char *key;  // 键值
    struct htItem *next;  // 链表指针
}htitem;

#endif /* HashTable_h */
