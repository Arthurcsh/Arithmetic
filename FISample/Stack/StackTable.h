//
//  StackTable.h
//  FISample
//
//  Created by chengshaohua on 2020/5/2.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef StackTable_h
#define StackTable_h

#include <stdio.h>

#define MAXSTACK 10
typedef int SElemType;

typedef struct Stack {
    SElemType *data;   // 栈数据
    int stackTop;      // 栈顶标记
    int size;
} Stack;


Stack* createStack(int size);

int stack_pop(Stack *stack, SElemType *data);

void binary_stack(int num);

#endif /* StackTable_h */
