//
//  DoubleLinker.h
//  FISample
//
//  Created by chengshaohua on 2020/5/18.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef DoubleLinker_h
#define DoubleLinker_h

#include <stdio.h>

typedef int DLElemType;

typedef struct DNode {
    DLElemType data;
    struct DNode *front;
    struct DNode *tail;
}DNode, *LPDNode;


#endif /* DoubleLinker_h */
