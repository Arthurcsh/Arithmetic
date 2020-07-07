//
//  StackTable.c
//  FISample
//
//  Created by chengshaohua on 2020/5/2.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "StackTable.h"
#include <stdlib.h>

// 创建栈
Stack* createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(stack));
    stack->data = (SElemType *)malloc(sizeof(SElemType)*size);
    stack->stackTop = -1;
    stack->size = size;
    
    return stack;
}

/**
 * 返回1表示NULL，0表示非空
 */
int stack_empty(Stack *stack) {
    return stack->stackTop == -1;
}

// 栈顶
int stack_peek(Stack *stack, SElemType *peek) {
    if (stack_empty(stack)) {
        return 0;
    }
    *peek = stack->data[stack->stackTop];
    return 1;
}

// 入栈
int stack_push(Stack *stack, SElemType data) {
    if (stack->data == NULL) {
        return 0;
    }
    
    // 判断栈溢出，top栈顶自增后设置
    if ((stack->stackTop + 1) < stack->size) {
        stack->data[++(stack->stackTop)] = data;
        return 1;
    } else {
        printf("栈满.");
        return 0;
    }
}

// 出栈
int stack_pop(Stack *stack, SElemType *data) {
    if (stack_empty(stack)) {
        printf("栈为空.");
        return 0;
    }
    
    *data = stack->data[(stack->stackTop)--];
    return 1;
}

// 遍历栈
void stack_iterator(Stack *stack) {
    if (stack_empty(stack)) return;
    printf("stack queue: ");
    
    int i, length=stack->stackTop;
    for (i=0;i<=length;i++) {
        SElemType item = stack->data[i];
        printf("%d ", item);
    }
    printf("\n");
}


// 判断栈是否为空

// 输入目标十进制转成二进制数值
void binary_stack(int num) {
    Stack *stack = createStack(50);
    while (num != 0) {
        stack_push(stack, num % 2);
        num /= 2;  // 除数自动除整
    }
    int data = 0;
    while (!stack_empty(stack)) {
        stack_pop(stack, &data);
        printf("%d", data);
    }
    printf("\n");
}

// 采用数组替换栈方法
void binary_array(int num) {
    int stackArray[50];
    int stackTop = -1;
    while (num != 0) {
        stackArray[++stackTop] = num % 2;
        num /= 2;
    }
    
    while (stackTop > -1) {
        printf("%d", stackArray[stackTop--]);
    }
    printf("\n");
}


// ***************
// 栈逆序B, 数组栈
void *stack_recursive(int stack[], int top) {
    if (top == 0) return stack;
    
    int peek = stack[top-1];
    stack_recursive(stack, top-1);
    int length = sizeof(*stack)/sizeof(stack[0]);
    stack[length-top] = peek;
    
    return stack;
}

int *reverseStack(int stack[], int top) {
    if (top <= 0) return stack;
    
    int i = 0;
    int a = stack[top-1];
    i++;
    
    stack = reverseStack(stack, top-1);
    i--;
    stack[i] = a;
    
    return stack;
}

void stack_reverse(int stack[], int top) {
    int count = top;
    int *result = stack_recursive(stack, top);
    
    int i;
    for (i=0;i<count;i++) {
        printf("%d", *result++);
    }
    printf("\n");
}

// 仅用递归函数和栈操作逆序一个栈
int getRemoveLastBottom(Stack *stack) {
    SElemType peek;
    stack_pop(stack, &peek);
    
    if (stack_empty(stack)) {
        return peek;   // stack为空返回栈底
    } else {
        SElemType result = getRemoveLastBottom(stack);
        stack_push(stack, peek);  // stack_pop()不为空才stack_push()，相当于去掉栈底
        return result;
    }
}

// 递归反转栈
void recursiveReverseStack(Stack *stack) {
    if (stack_empty(stack)) return;
    
    SElemType item = getRemoveLastBottom(stack);
    recursiveReverseStack(stack);
    stack_push(stack, item);  // 压入栈底元素
}

void stack_reverse_main() {
    Stack *reverse = createStack(20);
    stack_push(reverse, 1);
    stack_push(reverse, 2);
    stack_push(reverse, 3);
    stack_push(reverse, 4);
    stack_push(reverse, 5);
    
    recursiveReverseStack(reverse);
    stack_iterator(reverse);
}


/**
 * 栈数据排序：两个栈（数据栈+空栈）
 * 每次help中的数比cur大，则弹出，然后再push进cur（小）。
   一次循环，也就是help中的都时push进（从小到大的数，即小数压底）。
   直到stack弹空，在将help中的数压入stack，便完成了小数先输出的任务（后进先出）
 */
void stack_stack_sort(Stack *stack) {
    Stack *help = createStack(200);  // 辅助栈
    
    while (!stack_empty(stack)) {  // 直到stack中的值都存到help中
        int data;
        stack_pop(stack, &data);   // 弹出stack栈顶
        while (!stack_empty(help)) {
            int peek;
            stack_peek(help, &peek); // 比较help栈顶与当前从stack栈顶弹出的数据
            if (peek > data) {
                int temp;
                stack_pop(help, &temp);  // 如果help栈顶>data，则help栈顶压入stack
                stack_push(stack, temp);
            }
        }
        stack_push(help, data);  // 如果help栈顶<data，data压入help
    }
    
    while (!stack_empty(help)) {
        int rest;
        stack_pop(help, &rest);
        stack_push(stack, rest);
    }
}

void stack_sort_main() {
    Stack *stack = createStack(200);
    stack_push(stack, 1);
    stack_push(stack, 8);
    stack_push(stack, 3);
    stack_push(stack, 9);
    stack_push(stack, 5);
    stack_push(stack, 6);
    
    stack_iterator(stack);
    stack_stack_sort(stack);
    printf("stack sort after:\n");
    stack_iterator(stack);
}

/**
 * 简单的说，给出一个直方图，求里面可以画出的最大的矩形的面积
 */
int maxRectangleArea(int s[], int n) {
    int i, maxArea = -1, colArea = -1;
    int stack[n];
    int top = -1;
    
    for (i=0;i<=n;i++) {
        if (i < n) {
            colArea = s[i];  // 当前位置的直方图高度
        }

        // 如果当前高度<栈顶索引对应的高度，出栈计算当前位置直方图面积
        while (top != -1 && colArea <= s[stack[top]]) {
            int curHeigh = s[stack[top--]];  // 出栈
            int curWidth = i;
            if (top != -1) {
                curWidth = i - stack[top] -1;
            }
            maxArea = maxArea>curWidth*curHeigh?maxArea:curWidth*curHeigh;
        }
        // 如果栈为空，或者当前高度>=栈顶索引对应的高度，入栈
        stack[++top] = i;
    }
    printf("Max Rectangle Area: %d\n",maxArea);
    return maxArea;
}

/**
 * 整数数组积水问题
 */
int maxTrapWater(int s[], int n) {
    int max_index = 0;
    int max_sum = 0;
    int left = 0, right = 0;
    int i = 0;
    // 找到数组中最大的元素下标
    while (i < n && s[i] < s[max_index]) {
        max_index = i++;
    }
    
    // 计算左边部分
    for (i=0;i<max_index;i++) {
        if (s[i] > left) {
            left = s[i];
        } else {
            max_sum += left - s[i];
        }
    }
    // 计算右边部分
    for (i=n-1;i>max_index;i--) {
        if (s[i] > right) {
            right = s[i];
        } else {
            max_sum += right - s[i];
        }
    }
    return max_sum;
}
