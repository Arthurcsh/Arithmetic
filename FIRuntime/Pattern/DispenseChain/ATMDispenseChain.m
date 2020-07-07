//
//  ATMDispenseChain.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "ATMDispenseChain.h"

/**
 * https://juejin.im/post/5c8df92151882545bc34f7a5#heading-28
 */

@implementation ATMDispenseChain {
    DispenseChainNode *_firstChainNode;
    DispenseChainNode *_finalChainNode;
    int _minimumValue;
}

- (instancetype)initWithDispenseNodeValues:(NSArray *)nodeValues {
    if (self = [super init]) {
        NSUInteger length = nodeValues.count;
        for (int index = 0; index<length; index++) {
            NSNumber *nodeValue = nodeValues[index];
            DispenseChainNode *iterNode = [[DispenseChainNode alloc] initWithDispenseValue:[nodeValue intValue]];
            
            if (index == length - 1 ) {
                _minimumValue = [nodeValue intValue];
            }
            
            if (!self->_firstChainNode) {
                 //because this chain is empty, so the first node and the final node will refer the same node instance
                 _firstChainNode =  iterNode;
                 _finalChainNode =  _firstChainNode;
            } else {
                //appending the next node, and setting the new final node
                [_finalChainNode setNextChainNode:iterNode];
                 _finalChainNode = iterNode;
            }
        }
    }
    
    return self;
}

/**
 * DispenseChainNodeFor50Yuan *chainNode50 = [[DispenseChainNodeFor50Yuan alloc] init];
         DispenseChainNodeFor20Yuan *chainNode20 = [[DispenseChainNodeFor20Yuan alloc] init];
         DispenseChainNodeFor10Yuan *chainNode10 = [[DispenseChainNodeFor10Yuan alloc] init];
         
          _chainNode = chainNode50;
         [_chainNode setNextChainNode:chainNode20];
         [chainNode20 setNextChainNode:chainNode10];
 */


- (void)dispense:(int)amount {
    NSLog(@"==================================");
    NSLog(@"ATM start dispensing of amount:%d",amount);
    
    if (amount % _minimumValue != 0) {
        NSLog(@"Amount should be in multiple of %d",_minimumValue);
        return;
    }

    [ _firstChainNode dispense:amount];
    
}

@end
