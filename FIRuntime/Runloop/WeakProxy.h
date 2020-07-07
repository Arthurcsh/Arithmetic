//
//  WeakProxy.h
//  FIRuntime
//
//  Created by CSH on 2020/4/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WeakProxy : NSProxy

- (instancetype)initWithTarget:(id)target;

+ (instancetype)proxyWithTarget:(id)target;

@end

NS_ASSUME_NONNULL_END
