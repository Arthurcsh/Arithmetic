//
//  Context.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Context.h"

@implementation Context {
    
    TwoIntOperation *_operation;
    
}

- (instancetype)initWithOperation: (TwoIntOperation *)operation{
    if (self = [super init]) {
        //injection from instane initialization
        _operation = operation;
    }
    return self;
}

- (void)setOperation:(TwoIntOperation *)operation{
    
    //injection from setting method
    _operation = operation;
}

- (int)excuteOperationOfInt1:(int)int1 int2:(int)int2{
    
    //return value by constract strategy instane
    return [_operation operationOfInt1:int1 int2:int2];
}


@end
