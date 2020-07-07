//
//  LinkerTable.h
//  FISample
//
//  Created by CSH on 2020/4/19.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#ifndef LinkerTable_h
#define LinkerTable_h

#include <stdio.h>

#define MAXSIZE 10
typedef int NElemType;
typedef struct Node {
    NElemType data;
    struct Node *next;
} Node;

Node* initLinker();


#endif /* LinkerTable_h */
