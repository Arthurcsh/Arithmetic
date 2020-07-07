//
//  StackQueue.h
//  FISample
//
//  Created by chengshaohua on 2020/5/25.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef StackQueue_h
#define StackQueue_h

#include <stdio.h>
#include <stdbool.h>


/**
 * 双队列实现栈操作
 */

#define max_size 100

typedef char QData; // 队列数据类型

// 队列结构
typedef struct SQueue {
    QData *data;
    int head;
    int tail;
    int size;  // 循环队列环长度
}SQueue;

// 用双队列实现的栈
typedef struct QStack {
    SQueue queue1;   // 队列1
    SQueue queue2;   // 队列2
    int size;  // 栈中有效元素
} QStack;

void q_stack_init(QStack *stack);

void q_stack_push(QStack *stack, QData element);

void q_stack_pop(QStack *stack, QData *value);
    
QData* q_stack_peek(QStack *stack, QData *element);

bool q_stack_empty(QStack *stack);

size_t q_stack_length(QStack *stack);

#endif /* StackQueue_h */
