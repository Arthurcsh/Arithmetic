//
//  GCDGroup.m
//  FIRuntime
//
//  Created by CSH on 2020/4/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "GCDGroup.h"

@interface GCDGroup () {
    dispatch_queue_t concurrent_queue;
    NSMutableArray<NSURL*> *arrayURLs;
}

@end

@implementation GCDGroup

- (instancetype)init {
    if (self = [super init]) {
        // 创建并发队列
        concurrent_queue = dispatch_queue_create("com.group.queue", DISPATCH_QUEUE_CONCURRENT);
        arrayURLs = NSMutableArray.array;
    }
    return self;
}

- (void)groupHandle {
    // 创建gcd_group
    dispatch_group_t group = dispatch_group_create();
    
    // 遍历各个元素执行操作
    for (NSURL *url in arrayURLs) {
        // 异步组分派到并发队列中
        dispatch_group_async(group, concurrent_queue, ^{
            // 根据url下载图片耗时操作
            NSLog(@"-- url is %@", url);
        });
    }
    
    dispatch_group_notify(group, dispatch_get_main_queue(), ^{
        // 添加到组的所有任务执行完成之后调用group_notify，切换到主线程刷新UI
        NSLog(@"-- 所有图片已经全部下载完成");
    });
}


@end
