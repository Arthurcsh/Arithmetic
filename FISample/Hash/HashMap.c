//
//  HashMap.c
//  FISample
//
//  Created by chengshaohua on 2020/5/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "HashMap.h"
#include <stdlib.h>
#include <limits.h>

/**
 * 哈希的装填因子: a = m/n  其中n是关键字个数，m为表长度
 *
 * 装填因子是表示Hsah表中元素的填满的程度。加载因子越大,填满的元素越多,空间利用率提高,但冲突的机会加大了。
 * 反之,加载因子越小,填满的元素越少,冲突的机会减小了,但空间浪费多了。冲突的机会越大,则查找的成本越高。
 * 反之,查找的成本越小.因而,查找时间就越小.因此,必须在 "冲突的机会"与"空间利用率"之间寻找一种平衡
 */

// 由值简单的hashcode
int hash_code(HashMap *hashmap, int value) {
    return abs(value)%hashmap->size;
}

// 将给定的整形数组构建为HashMap,size为数组长度
HashMap* createHashMap(int *nums, int size) {
    // 分配内存空间
    HashMap *hashmap = (HashMap*)malloc(sizeof(HashMap));
    hashmap->size = 2*size;
    // hash表分配空间
    hashmap->table = (HashNode*)malloc(sizeof(HashNode)*hashmap->size);
    
    // 初始化
    int n, index = 0;
    for (n=0;n<hashmap->size;n++) {
        hashmap->table[n].data.value = INT_MIN;
        hashmap->table[n].next = NULL;
    }
    while (index < size) {
        // 根据数组元素的值计算其在hashmap中的位置
        int pos = hash_code(hashmap, nums[index]);
        // 判断是否冲突
        if (hashmap->table[pos].data.value == INT_MIN) {
            // 不冲突，把元素在数组中的索引作为key
            hashmap->table[pos].data.key = index;
            // 把元素值作为value
            hashmap->table[pos].data.value = nums[index];
        } else {
            // 冲突，给当前元素分配一个节点，并为节点赋值
            HashNode *lnode = (HashNode*)malloc(sizeof(HashNode));
            HashNode *hashnode;
            lnode->data.key = index;
            lnode->data.value = nums[index];
            lnode->next = NULL;
            // 从冲突位置开始，遍历链表
            hashnode = &(hashmap->table[pos]);
            while (hashnode->next != NULL) {
                hashnode = hashnode->next;
            }
            // 将当前节点连接到链表尾部
            hashnode->next = lnode;
        }
        index++;
    }
    // 处理完成，返回HashMap
    return hashmap;
}

int get(HashMap hashmap, int value) {
    // 根据元素值，计算其位置
    int pos = hash_code(&hashmap, value);
    HashNode *pointer = &(hashmap.table[pos]);
    // 在当前链表遍历查找该节点
    while (pointer != NULL) {
        if (pointer->data.value == value) {
            return pointer->data.key;
        } else {
            pointer = pointer->next;
        }
    }
    
    return -1;
}

int put(HashMap hashmap, int key, int value) {
    int pos = hash_code(&hashmap, value);
    HashNode *pointer = &(hashmap.table[pos]);
    if (pointer->data.value == INT_MIN) {
        pointer->data.value = value;
        pointer->data.key = key;
    } else {
        while (pointer->next != NULL) {
            pointer = pointer->next;
        }
        HashNode *hashnode = (HashNode*)malloc(sizeof(HashNode));
        hashnode->data.key =key;
        hashnode->data.value = value;
        hashnode->next = NULL;
        pointer->next = hashnode;
    }
    
    return 1;
}

void destory(HashMap *hashmap) {
    int i = 0;
    HashNode *pointer;
    while (i < hashmap->size) {
        pointer = hashmap->table[i].next;
        while (pointer != NULL) {
            hashmap->table[i].next = pointer->next;
            // 逐个释放节点空间，防止内存溢出
            free(pointer);
            pointer = hashmap->table[i].next;
        }
        i++;
    }
    free(hashmap->table);
    free(hashmap);
    printf("hashmap destory success!\n");
}

void printHashMap(HashMap *hashmap) {
    printf("===========PrintHashMap==========\n");
    int i=0;
    HashNode *pointer;
    while(i<hashmap->size){
        pointer=&(hashmap->table[i]);
        while(pointer!=NULL){
            if(pointer->data.value!=INT_MIN)
                printf("%10d",pointer->data.value);
            else
                printf("        [ ]");
            pointer=pointer->next;
        }
        printf("\n---------------------------------");
        i++;
        printf("\n");
    }
    printf("===============End===============\n");
}

void hash_map_main() {
    int nums[] = {34,54,32,32,56,78};
    //创建HashMap
    HashMap *hashmap = createHashMap(nums,6);
    printHashMap(hashmap);
    //查找元素
    printf("%d\n",get(*hashmap,78));
    
    destory(hashmap);
}

