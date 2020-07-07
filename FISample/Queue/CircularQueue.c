//
//  CircularQueue.c
//  FISample
//
//  Created by CSH on 2020/4/18.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "CircularQueue.h"
#include <stdbool.h>
#include <stdlib.h>

typedef int QElemType;

typedef struct {
    QElemType *data;
    int front;  // 队首
    int tail;   // 队尾
    int size;   // 长度
}SqQueue;

/**
 * 环形队列四要素：
 队空：rear==front;
 队满：(rear+1)%MaxSize == front;
 进栈：rear = (rear+1)%MaxSize; data[rear] = e;
 出栈：front = (front+1)%MaxSize; e = data[front];

 由此可以看出环形队列只能存储MaxSize-1个元素，front指向的元素为无效元素。
 *
 *
 *延伸：对于已知front，rear，count（队列中元素个数）三者知其二，都可求出另外一个。（默认MaxSize已知）

 已知front，rear，求元素个数count
 count = (rear-front+MaxSize)%MaxSize
 
 已知front，count，求尾指针rear
 rear = (front+count)%MaxSize
 
 已知count，rear，求头指针front
 front = (rear-count+MaxSize)%MaxSize
 */

SqQueue* circularQueueCreate(int size) {
    SqQueue *queue = NULL;
    queue->data = (QElemType *)malloc(sizeof(QElemType)*size);
    queue->front = queue->tail = 0;
    queue->size = size;
    
    return queue;
}

/**
 * 是否空循环队列
 */
bool circularQueueIsEmpty(SqQueue* queue) {
    return (queue->front == queue->tail);
}

/**
 * 是否循环队列已满
 */
bool circularQueueIsFull(SqQueue* queue) {
    return ((queue->tail+1)%queue->size == queue->front);
}

/**
 * 插入队列
 */
bool circularQueueEnQueue(SqQueue* queue, QElemType value) {
    // 队列已满直接返回
    if (circularQueueIsFull(queue)) {
        return false;
    }
    queue->data[queue->tail] = value;
    queue->tail = (queue->tail+1)%queue->size; // 尾指针偏移，重新回到数组的初始地址，继续入队，于是这就形成了循环队列。
    
    return true;
}

/**
 * 出队列
 */
bool circularQueueDeQueue(SqQueue* queue, QElemType *value) {
    if (circularQueueIsEmpty(queue)) {
        return false;
    }
    
    // 删除队列头元素
    *value = queue->data[queue->front];
    queue->front = (queue->front+1)%queue->size;  // 队列头指针+1
    return true;
}

QElemType circularQueueFront(SqQueue* queue) {
    if (circularQueueIsEmpty(queue)) {
        return -1;
    }
    
    return queue->data[queue->front];
}

QElemType circularQueueTail(SqQueue* queue) {
    if (circularQueueIsEmpty(queue)) {
        return -1;
    }
    
    return queue->data[queue->tail];
}

/**
 * 环队列长度: （队尾-队头+队列长度)%队列长度 = 队列环长
 */
int circularQueueLength(SqQueue* queue) {
    return (queue->tail-queue->front + queue->size)%queue->size;
}

void circularQueueFree(SqQueue* queue) {
    free(queue);
}

// 不使用其他数据结构逆序队列
void recursiveQueue(SqQueue *queue) {
    if (circularQueueIsEmpty(queue)) return;
    
    QElemType item;
    circularQueueDeQueue(queue, &item);
    recursiveQueue(queue);
    circularQueueEnQueue(queue, item);
}

