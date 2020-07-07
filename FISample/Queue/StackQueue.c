//
//  StackQueue.c
//  FISample
//
//  Created by chengshaohua on 2020/5/25.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "StackQueue.h"
#include "StackTable.h"
#include <stdlib.h>

/**
 * 双栈队列
 */
typedef struct stackQueue {
    Stack *pop_stack;
    Stack *push_stack;
} StackQueue, *PSQueue;

/**
 * 创建栈式队列
 */
PSQueue create_stack_queue() {
    PSQueue queue = (PSQueue)malloc(sizeof(StackQueue));
    queue->pop_stack = createStack(20);
    queue->push_stack = createStack(20);
    
    return queue;
}

// 编写一个类，只能用两个栈结构实现队列的基本操作(add, poll, peek);

// 加入队列, 如果stack_push往stack_pop中倒入数据， 必须stack_push中所有数据一次性倒完
void add_queue(PSQueue queue, SElemType element) {
    if (NULL == queue) {
        printf("NULL queue.\n");
        exit(1);
    }
    
    stack_push(queue->push_stack, element);
}

// 出队列
int poll_queue(PSQueue queue) {
    if (NULL == queue) {
        printf("NULL queue.\n");
        exit(1);
    }
    
    if (stack_empty(queue->push_stack) && stack_empty(queue->pop_stack)) {
        printf("no element.\n");
        exit(1);
    } else if (stack_empty(queue->pop_stack)) {
        while (queue->push_stack->stackTop != -1) {
            SElemType peek;
            stack_pop(queue->push_stack, &peek);
            stack_push(queue->pop_stack, peek);
        }
    }
    SElemType tmp;
    stack_pop(queue->pop_stack, &tmp);
    
    return tmp;
}

// 查看队列元素， 如果空队列返回null
int peek_queue(PSQueue queue) {
    if (NULL == queue) {
        printf("NULL queue.\n");
        exit(1);
    }
    
    printf("stack queue: ");
    if (!stack_empty(queue->push_stack)) {
        int i, length=queue->push_stack->stackTop;
        for (i=length;i>-1;i--) {
            SElemType item = queue->push_stack->data[i];
            printf("%d ", item);
        }
    }
    if (!stack_empty(queue->pop_stack)) {
        int i, length=queue->pop_stack->stackTop;
        for (i=0;i<=length;i++) {
            SElemType item = queue->pop_stack->data[i];
            printf("%d ", item);
        }
    }
    printf("\n");
    
    return 1;
}
int peek_two_stack(PSQueue queue, SElemType *peek) {
    if (stack_empty(queue->push_stack) && stack_empty(queue->pop_stack)) {
        printf("no element.\n");
        return 0;
    } else if (stack_empty(queue->pop_stack)) {
        while (!stack_empty(queue->push_stack)) {
            SElemType data;
            stack_pop(queue->push_stack, &data);
            stack_push(queue->pop_stack, data);
        }
    }
    stack_peek(queue->pop_stack, peek);
    
    return 1;
}

// 队列长度
int length_queue(PSQueue queue) {
    if (queue == NULL) return 0;
    
    int queue_length = 0;
    if (!stack_empty(queue->push_stack)) {
        queue_length += queue->push_stack->stackTop;
    }
    if (!stack_empty(queue->pop_stack)) {
        queue_length += queue->pop_stack->stackTop;
    }
    return queue_length;
}


void queue_stack_main() {
    PSQueue queue = create_stack_queue();
    add_queue(queue, 3);
    add_queue(queue, 8);
    add_queue(queue, 5);
    add_queue(queue, 4);
    add_queue(queue, 1);
    
    poll_queue(queue);
    peek_queue(queue);
    
    add_queue(queue, 0);
    poll_queue(queue);
    poll_queue(queue);
    add_queue(queue, 2);
    add_queue(queue, 9);
    peek_queue(queue);
}



/**
 * 队列定义
 */

// 队列初始化函数
void queue_init(SQueue *queue) {
    if (queue == NULL) return;
    queue->data = (QData *)malloc(sizeof(QData)*max_size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = max_size;
}

// 循环队列是否空
bool queue_empty(SQueue *queue) {
    return queue->tail == queue->head;
}

// 循环队列是否已满
bool queue_full(SQueue *queue) {
    return (queue->tail+1)%queue->size == queue->head;
}

// 入队列
void queue_en(SQueue *queue, QData element) {
    if (queue == NULL) return;
    if (queue_full(queue)) {
        printf("队列已满了");
        return;
    }
    
    queue->data[queue->tail] = element;
    // 尾指针偏移，重新回到数组的初始地址，继续入队，于是这就形成了循环队列。
    queue->tail = (queue->tail+1)%queue->size;
}

// 出队列
void queue_de(SQueue *queue, QData *data) {
    if (queue_empty(queue)) {
        printf("队列是空的");
        return;
    }
    
    *data = queue->data[queue->head];
    // 头指针偏移
    queue->head = (queue->head+1)%queue->size;
}

// 取队列头元素
QData* queue_peek(SQueue *queue) {
    if (queue_empty(queue)) {
        printf("队列是空的");
        return NULL;
    }
    return &queue->data[queue->head];
}

// 循环队列长度 length = (tail-head+MaxSize)%MaxSize
int queue_length(SQueue *queue) {
    return (queue->tail-queue->head + queue->size)%queue->size;
}

// 销毁队列
void queue_destory(SQueue *queue) {
    if (!queue) return;
    
    free(queue->data);
    queue->data = NULL;
    queue->head = queue->tail = queue->size = 0;
}


/**
* ----------- 双队列实现栈操作 ------------
*/

/**
 * 栈初始化
 */
void q_stack_init(QStack *stack) {
    if (stack == NULL) return;
    
    queue_init(&stack->queue1);
    queue_init(&stack->queue2);
    stack->size = 0;
}

// 入栈
void q_stack_push(QStack *stack, QData element) {
    if (stack == NULL) return;
    
    // 入栈找到不为空的那个队列
    SQueue *push = NULL;
    // 队列1不为空，push
    if (!queue_empty(&stack->queue1)) {
        push = &stack->queue1;
    } else {
        // 否则队列2不为空，或者两个队列都为空, 随便en那个队列都可以
        push = &stack->queue2;
    }
    queue_en(push, element);
    stack->size++;  // 每次入栈，栈有效元素个数+1
}

// 出栈
void q_stack_pop(QStack *stack, QData *value) {
    if (stack == NULL || stack->size ==0) return;
    
    SQueue *de_queue = NULL;
    SQueue *en_queue = NULL;
    // 将不为空的队列元素转移到空队列，queue1和queue2至少有个队列不为空，另一个为空
    if (!queue_empty(&stack->queue1)) {
        de_queue = &stack->queue1;
        en_queue = &stack->queue2;
    } else {
        de_queue = &stack->queue2;
        en_queue = &stack->queue1;
    }
    // 首先确保en_queue为空，将de_queue中元素转移到en_queue，但是保留队列尾最后一个元素
    if (queue_empty(en_queue)) {
        while (queue_length(de_queue) > 1) {
            QData de_data;
            // 不为空队列出队列
            queue_de(de_queue, &de_data);
            
            // de_queue出队列元素进入en_queue队列
            queue_en(en_queue, de_data);
        }
    }
    
    // 循环结束，de_queue队列尾最后一个元素
    queue_de(de_queue, value);
    // 栈总有效元素个数-1
    stack->size--;
}

/** 取栈顶元素：与出栈操作类似，唯一不同的就是，将元素移动到剩下最后一个元素时不要出队列，而是返回该元素，这个元素依然存在该栈中，为确保至少一个队列为空， 读取完成后也要转移到en_queue队列中去
 **/
QData* q_stack_peek(QStack *stack, QData *element) {
    if (stack == NULL || stack->size ==0) return NULL;
    
    // queue1&queue2至少有个队列不为空
    if (!queue_empty(&stack->queue1)) {
        return queue_peek(&stack->queue1);
    } else {
        return queue_peek(&stack->queue2);
    }
    return NULL;
}

/**
 * 双队列实现栈是否空
 */
bool q_stack_empty(QStack *stack) {
    if (stack == NULL || stack->size ==0) return true;
    if (queue_empty(&stack->queue1) && queue_empty(&stack->queue2)) {
        return true;
    } else {
        return false;
    }
}

/**
 * 栈长度
 */
size_t q_stack_length(QStack *stack) {
    if (stack == NULL || stack->size ==0) return 0;
    
    if (queue_empty(&stack->queue1) && queue_empty(&stack->queue2)) {
        return 0;
    } else if (!queue_empty(&stack->queue1)) {
        return queue_length(&stack->queue1);
    } else {
        return queue_length(&stack->queue2);
    }
}


// 销毁
void q_stack_destory(QStack *stack) {
    if (stack == NULL) return;
    
    queue_destory(&stack->queue1);
    queue_destory(&stack->queue2);
}

void stack_queue_main() {
    QStack qstack;
    q_stack_init(&qstack);
    q_stack_push(&qstack, 'm');
    q_stack_push(&qstack, '8');
    q_stack_push(&qstack, 'b');
    q_stack_push(&qstack, 'u');
    q_stack_push(&qstack, 'a');
    q_stack_push(&qstack, '5');
    
    char pop;
    q_stack_pop(&qstack, &pop);
    q_stack_push(&qstack, 't');
    q_stack_push(&qstack, 'e');
    char data;
    q_stack_pop(&qstack, &data);
    printf("two queue stack pop: %c\n",data);
}
