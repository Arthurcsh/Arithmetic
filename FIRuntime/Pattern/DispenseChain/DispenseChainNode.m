//
//  DispenseChainNode.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "DispenseChainNode.h"

@implementation DispenseChainNode

- (instancetype)initWithDispenseValue:(int)dispenseValue {
    if (self = [super init]) {
        _dispenseValue = dispenseValue;
    }
    return self;
}

- (void)setNextChainNode:(DispenseChainNode *)chainNode {
    
    _nextChainNode = chainNode;
}


#pragma DispenseProtocol

- (void)dispense:(int)amount {
    if (amount >= _dispenseValue) {
        int count = amount / _dispenseValue;
        int remainder = amount % _dispenseValue;
        NSLog(@"Dispensing %d of %d",count,_dispenseValue);
        
        if (remainder != 0) {
            [_nextChainNode dispense:remainder];
        }
    } else {
        [_nextChainNode dispense:amount];
    }
    return;
}

@end
