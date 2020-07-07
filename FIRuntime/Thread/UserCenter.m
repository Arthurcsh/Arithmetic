//
//  UserCenter.m
//  FIRuntime
//
//  Created by CSH on 2020/4/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "UserCenter.h"

@interface UserCenter() {
    // 定义并发队列
    dispatch_queue_t concurrent_queue;
    
    // 用户数据中心，多线程访问
    NSMutableDictionary *userCenter;
}

@end

/**
 * 读写锁，用户数据安全，多线程并发访问
 */
@implementation UserCenter

- (instancetype)init {
    if (self = [super init]) {
        concurrent_queue = dispatch_queue_create("com.center.queue", DISPATCH_QUEUE_CONCURRENT);
        userCenter = NSMutableDictionary.dictionary;
        
    }
    return self;
}

- (id)objectForKey:(NSString *)key {
    if (!key) {
        return nil;
    }
    __block id obj;
    // 同步读取数据, 立刻返回
    dispatch_sync(concurrent_queue, ^{
        obj = [userCenter objectForKey:key];
    });
    return obj;
}

- (void)setObject:(id)obj forKey:(NSString *)key {
    if (!obj || !key) {
        return;
    }
    
    // 异步栅栏调用设置数据
    dispatch_barrier_async(concurrent_queue, ^{
        [self->userCenter setObject:obj forKey:key];
    });
}

@end
