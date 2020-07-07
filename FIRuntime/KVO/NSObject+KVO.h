//
//  NSObject+KVO.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/7/1.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^DeallocCallbackTask)(id obj);

@interface NSObject (DeallocCallback)
/// Add a task that will be executed when the object is destroyed
/// 添加一个任务, 当对象销毁时将会执行这些任务
- (void)csh_addDeallocCallbackTask:(DeallocCallbackTask)blockTask;
@end


@interface NSObject (KVO)

@end

NS_ASSUME_NONNULL_END
