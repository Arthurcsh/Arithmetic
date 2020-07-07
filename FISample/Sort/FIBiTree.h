//
//  FIBiTree.h
//  FISample
//
//  Created by chengshaohua on 2017/11/30.
//  Copyright © 2017年 www.bundwealth.com. All rights reserved.
//

#ifndef FIBiTree_h
#define FIBiTree_h

typedef struct Node
{
    char data;
    struct Node* Lchild;
    struct Node* Rchild;
    struct Node* parent;
}BiTNode,*BiTree;

#include <stdio.h>

#endif /* FIBiTree_h */
