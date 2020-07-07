//
//  ATMDispenseChain.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DispenseChainNode.h"

NS_ASSUME_NONNULL_BEGIN

@interface ATMDispenseChain : NSObject <DispenseProtocol>

- (instancetype)initWithDispenseNodeValues:(NSArray *)nodeValues;

@end

NS_ASSUME_NONNULL_END
