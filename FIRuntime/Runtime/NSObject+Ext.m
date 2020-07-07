//
//  NSObject+Ext.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "NSObject+Ext.h"
#import <objc/runtime.h>

static NSString *WEAK_KEY = @"weakObj";
static NSString *BLOCK_KEY = @"block";

@implementation NSObject (Ext)

- (id)weakObj {
    return objc_getAssociatedObject(self, &WEAK_KEY);
}

- (void)setWeakObj:(id)weakObj {
    [weakObj setBlock:^{
        objc_setAssociatedObject(self, &WEAK_KEY, nil, OBJC_ASSOCIATION_ASSIGN);
    }];
    objc_setAssociatedObject(self, &WEAK_KEY, weakObj, OBJC_ASSOCIATION_ASSIGN);
}

- (DeallocBlock)block {
    return objc_getAssociatedObject(self, &BLOCK_KEY);
}

- (void)setBlock:(DeallocBlock)block {
    objc_setAssociatedObject(self, &BLOCK_KEY, block, OBJC_ASSOCIATION_COPY);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"
- (void)dealloc {
    self.block ? self.block() : nil;
    objc_setAssociatedObject(self, &BLOCK_KEY, nil, OBJC_ASSOCIATION_ASSIGN);
}
#pragma clang diagnostic pop


@end
