//
//  GCDTread.m
//  FIRuntime
//
//  Created by CSH on 2020/4/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "GCDTread.h"

typedef void (^group_block_t)(void);
typedef id (^final_block_t)(id obj);

/**
 *
 * semaphore信号量的原理就是生产-消费模式，必须生产一定资源才能消费，没有资源的时候，啥也不干，直到资源就绪
 */
@implementation GCDTread

/**
 * 子线程同时执行ABC三个同步任务、全部执行完成再在子线程执行三个同步任务D
 */
+ (void)concurrentGroupSemaphore {
    dispatch_group_t group = dispatch_group_create();
    dispatch_queue_t queue = dispatch_queue_create("com.semphore.queue", DISPATCH_QUEUE_CONCURRENT);
    
    // 传入的参数value必须大于或等于0，否则dispatch_semaphore_create会返回NULL
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);  // 创建空信号量
    
    dispatch_group_async(group, queue, ^{
        NSLog(@"同步任务A");
        // 假设异步线程执行完成后返回
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2.0f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSLog(@"网络异步任务一");
            dispatch_semaphore_signal(semaphore);  // 信号量+1
        });
        // 如果semaphore==0，阻塞当前线程，直到semaphore>0，或者timeout
        // 执行dispatch_semaphore_wait后，semaphore的值减1
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    });
    
    dispatch_group_async(group, queue, ^{
        NSLog(@"同步任务B");
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.8f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSLog(@"网络异步任务二");
            dispatch_semaphore_signal(semaphore);
        });
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    });
    
    dispatch_group_async(group, queue, ^{
        NSLog(@"同步任务C");
    });
    dispatch_group_async(group, queue, ^{
        NSLog(@"同步任务D");
        // 延迟回调，模拟网络请求
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3.5f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSLog(@"网络异步任务四");
            dispatch_semaphore_signal(semaphore);
        });
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    });
    
    // 以上组任务执行完成后，通知下面的任务最后执行
    dispatch_group_notify(group, queue, ^{
        NSLog(@"任务完成执行");
    });
}


@end
