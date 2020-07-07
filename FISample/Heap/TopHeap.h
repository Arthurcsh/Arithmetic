//
//  TopHeap.h
//  FISample
//
//  Created by chengshaohua on 2020/6/4.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef TopHeap_h
#define TopHeap_h

#include <stdio.h>
#include <stddef.h>

#define HeapMaxSize 1000

typedef int  HData;
typedef int (*compare)(HData a, HData b);

/**
 * 堆结构
 */
typedef struct Heap {
    HData *data;
    int length;
    int max_size;
    compare cmp;
}Heap;


#endif /* TopHeap_h */
