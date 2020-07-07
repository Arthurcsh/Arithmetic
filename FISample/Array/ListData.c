//
//  ListData.c
//  FISample
//
//  Created by chengshaohua on 2020/5/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "ListData.h"
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

// 数据节点结构
typedef struct {
    char key[10];
    char name[20];
    int age;
} DATA;

// 定义顺序表结构
typedef struct {
    DATA ListData[MAXLEN];  // 顺序表结构数组
    int ListLen;    // 顺序表节点数量
}SLType;

// 顺序表结构初始化
void SLInit(SLType *list) {
    list->ListLen = 0;
}

// 顺序表长度
int SLLenght(SLType *list) {
    return list->ListLen;
}

// 顺序表n位置插入节点
int SLInsert(SLType *list, int n, DATA data) {
    if (!list || list->ListLen<n) return 0;
    if (list->ListLen >= MAXLEN) {
        printf("顺序表已满，不能插入节点！\n");
        return 0;
    }
    
    int i;
    for (i=list->ListLen;i>=n;i--) {
        list->ListData[i+1] = list->ListData[i];
    }
    list->ListData[i] = data;
    list->ListLen++;
    
    return 1;
}

// 增加元素到顺序表尾部
int SLAdd(SLType *list, DATA data) {
    if (list->ListLen >= MAXLEN) {
        printf("顺序表已满，不能插入节点！\n");
        return 0;
    }
    list->ListData[list->ListLen++] = data;
    
    return 1;
}

// 删除顺序表中第n个节点
int SLDelete(SLType *list, int n) {
    if (n<1 || n > list->ListLen) {
        return 0;
    }
    
    int i;
    for (i=n;i<list->ListLen;i++) {
        list->ListData[i] = list->ListData[i+1];
    }
    list->ListLen--;
    
    return 1;
}

// 根据序号查找数据元素
DATA* SLFindByNum(SLType *list, int n) {
    if (n > MAXLEN || n < list->ListLen) {
        printf("顺序表序号错误！\n");
        return NULL;
    }
    
    return &list->ListData[n];
}

// 按关键字查找节点
int SLFindByKey(SLType *list, char *key) {
    int index = -1;
    for (index=1;index<list->ListLen;index++) {
        if (strcmp(list->ListData[index].key, key) == 0) {
            return index;
        }
    }
    return index;
}
