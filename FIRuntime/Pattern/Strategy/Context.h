//
//  Context.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "TwoIntOperation.h"
@class TwoIntOperation;

NS_ASSUME_NONNULL_BEGIN

@interface Context : TwoIntOperation

- (instancetype)initWithOperation: (TwoIntOperation *)operation;

- (void)setOperation:(TwoIntOperation *)operation;

- (int)excuteOperationOfInt1:(int)int1 int2:(int)int2;


@end

NS_ASSUME_NONNULL_END
