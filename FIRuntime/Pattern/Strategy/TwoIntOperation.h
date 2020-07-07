//
//  TwoIntOperation.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 抽象策略
 */
@interface TwoIntOperation : NSObject

- (int)operationOfInt1:(int)int1 int2:(int)int2;

@end

NS_ASSUME_NONNULL_END
