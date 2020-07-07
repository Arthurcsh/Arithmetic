//
//  DispenseChainNode.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 责任链协议
 */
@protocol DispenseProtocol <NSObject>

// 分发责任链
- (void)dispense:(int)amount;

@end

/**
 * 责任链节点
 */
@interface DispenseChainNode : NSObject <DispenseProtocol> {
    
@protected DispenseChainNode *_nextChainNode;
@protected int _dispenseValue;
    
}

- (instancetype)initWithDispenseValue:(int)dispenseValue;

- (void)setNextChainNode:(DispenseChainNode *)chainNode;

@end

NS_ASSUME_NONNULL_END
