//
//  TopHeap.c
//  FISample
//
//  Created by chengshaohua on 2020/6/4.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "TopHeap.h"
#include <stdlib.h>
#include <stdbool.h>

//如果a小于b，就返回1，否则返回0
int less(HData a, HData b) {
    return a < b;
}

/**
 * 堆初始化
 */
void initHeap(Heap *heap, int max) {
    if (max <= 0) return;
    
    heap->data = (HData *)malloc(sizeof(HData)*max);
    heap->length = 0;
    heap->max_size = max;
}

/**
 * 堆是否空
 */
bool heap_empty(Heap *heap) {
    if (heap->length == 0) {
        return true;
    }
    return false;
}


/**
 * 堆向上调整(小顶堆)
 * 堆任意一个下标i(0<=i<=n-1)
 * i=0是根节点，没有双亲，否则节点i的双亲为节点(i-1)/2
 * 如果2*i+1 <= n-1，则节点i的左孩子为节点2*i+1，否则节点i无左孩子
 * 如果2*i+2 <= n-1,则节点i的右孩子为节点 2*i+2，否则节点i无右孩子
 */
void heap_adjust_up(Heap *heap, int index) {
    if (heap->max_size <= index) return;
    
    HData last = heap->data[index];
    while (index > 0) {
        int parent = (index - 1)/2;  // parent为下标index的双亲
        if (last >= heap->data[parent]) {
            //若新元素大于待调整元素的双亲，则比较调整结束，退出循环
            break;
        } else {
            heap->data[index] = heap->data[parent]; //将双亲元素下移到待调整元素的位置
            index = parent; //使待调整位置变为其双亲位置，进行下一次循环
        }
    }
    heap->data[index] = last;  //把新元素调整到最终位置
}

/**
 * 堆插入
 */
void heap_insert(Heap *heap, HData element) {
    // 如果堆满，扩容为x2
    if (heap->length == heap->max_size) {
        HData *data = realloc(heap->data,sizeof(HData)*2*heap->max_size);
        heap->data = data;
        heap->max_size = 2*heap->max_size;
        printf("存储空间已扩展原来2倍\n");
    }
    
    int index = heap->length;
    heap->data[(heap->length)] = element;  // 向堆尾添加新元素，
    heap->length++; // 堆长自增+1
    heap_adjust_up(heap, index);
}

/**
 * 堆向下调整
 */
void heap_adjust_down(Heap *heap) {
    if (heap->max_size <= 0) return;
    
    int root = 0;
    int left = 2*root + 1;
    HData data = heap->data[heap->length];  //暂存堆顶元素
    //寻找待调整元素的最终位置，每次使孩子元素上移一层，调整到孩子为空时止
    while (left <= heap->length-1) {
        if (left < heap->length-1 && heap->data[left] > heap->data[left+1]) {
            left++;  //若存在右孩子且较小，使left指向右孩子
        }
        if (data <= heap->data[left]) {
            break;  //若x比其较小的孩子还小，则调整结束，退出循环
        }
        heap->data[root] = heap->data[left]; //否则，将孩子元素移到双亲位置
        root = left;   //将待调整位置变为其较小的孩子位置
        left = 2*root + 1;  //将j变为新的待调整位置的左孩子位置，继续下一次循环
    }
    heap->data[root] = data;  //把x放到最终位置
}

/**
 * 从堆中删除堆顶元素并返回
 */
HData heap_delete(Heap *heap) {
    if (heap->length == 0) {
        printf("堆已空，退出运行！\n");
        exit(1);
    }
    HData root = heap->data[0];  // 暂存堆顶元素
    if ((heap->length)-- == 0) {
        return root;
    }
    
    heap_adjust_down(heap);
    return root;
}

void heap_free(Heap *heap) {
    
}


void main_heap() {
    Heap heap;
    initHeap(&heap, 100);
    heap_insert(&heap, 7);
    heap_insert(&heap, 3);
    heap_insert(&heap, 1);
    heap_insert(&heap, 6);
    heap_insert(&heap, 10);
    heap_insert(&heap, 2);
    int i;
    for (i=0;i<6;i++) {
        printf(" %d", heap.data[i]);
    }
    printf("\n");
}
