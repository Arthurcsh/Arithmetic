//
//  FILock.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/7/3.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "FILock.h"
#import <libkern/OSAtomic.h>
#import <os/lock.h>
#import <pthread.h>

/**
 *  有4个术语比较容易混淆：同步、异步、并发、串行
     同步和异步主要影响：能不能开启新的线程
     同步：在当前线程中执行任务，不具备开启新线程的能力
     异步：在新的线程中执行任务，具备开启新线程的能力

     并发和串行主要影响：任务的执行方式
     并发：多个任务并发（同时）执行
     串行：一个任务执行完毕后，再执行下一个任务
 */
@implementation FILock

/**
 * 自旋锁：等待锁的线程会处于忙等(busy-wait)状态，一直占用CPU资源
 * 目前已经验证不再安全，可能出现优先级反转问题
 * 如果等待锁的线程优先级较高，它会一直占用CPU资源，优先级低的线程任务结束后无法释放锁
 * 运行效率较高，主要用于线程任务较短时间的共享资源数据安全,小场景下的一个高效锁,否则会大量消耗cpu资源
 */
- (void)spinLock {
    // 初始化自旋锁
//    OSSpinLock lock = OS_SPINLOCK_INIT;
//    bool result = OSSpinLockTry(&lock);
//    // 加锁
//    OSSpinLockLock(&lock);
//    // 解锁
//    OSSpinLockUnlock(&lock);
}

/**
 * 互斥锁：互斥锁运行效率最高
 * 用于取代不安全的OSSpinLock, 从iOS10后开始支持
 * 等待unfair_lock锁的线程会处于休眠状态，并非忙等
 * 但是释放锁唤醒等待线程，线程之间切换的上下文会消耗CPU资源
 */
- (void)unfairLock {
    os_unfair_lock lock = OS_UNFAIR_LOCK_INIT;
    // 尝试加锁
    bool result = os_unfair_lock_trylock(&lock);
    // 加锁
    os_unfair_lock_lock(&lock);
    // 解锁
    os_unfair_lock_unlock(&lock);
}

/**
 * 互斥锁：等待锁的线程会处于休眠状态
 */
- (void)mutexLock {
    // 初始化锁属性
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
    
    // 初始化
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, &attr);
    
    // 尝试加锁
    pthread_mutex_trylock(&mutex);
    
    // 加锁
    pthread_mutex_lock(&mutex);
    
    // 解锁
    pthread_mutex_unlock(&mutex);
}

/**
 * NSLock: NSLock是对mutex普通锁的封装
 * NSReccursiveLock: 也是对mutex递归锁的封装
 */
- (void)nslock {
    // 初始化
    NSLock *lock = [[NSLock alloc] init];
    
    [lock tryLock];
    
    [lock lock];
    
    [lock unlock];
}

/**
 * pthread_rwlock: 读写锁
 * 等待锁的线程会进入休眠状态
 *
 * 1. 当读写锁被一个线程以读模式占用的时候，写操作的其他线程会被阻塞，读操作的其他线程还可以继续进行。
   2. 当读写锁被一个线程以写模式占用的时候，写操作的其他线程会被阻塞，读操作的其他线程也被阻塞。
 */
- (void)readWriteLock {
    // 初始化锁
    pthread_rwlock_t lock;
    pthread_rwlock_init(&lock, NULL);
    
    // 读-加锁
    pthread_rwlock_rdlock(&lock);
    pthread_rwlock_tryrdlock(&lock);
    
    // 写-加锁
    pthread_rwlock_wrlock(&lock);
    pthread_rwlock_trywrlock(&lock);
    
    // 解锁
    pthread_rwlock_unlock(&lock);
    
    // 销毁
    pthread_rwlock_destroy(&lock);
    
}

/**
 * 栅栏控制读写，保障共享内存数据安全
 */
- (void)barrierLock {
    NSMutableSet *share = [NSMutableSet new];
    
    // 初始化
    dispatch_queue_t queue = dispatch_queue_create("barrier.queue.locck", DISPATCH_QUEUE_CONCURRENT);
    
    // 读取, 确保同步返回
    __block id item;
    dispatch_sync(queue, ^{
        item = [share allObjects];
    });
    
    // 写入
    dispatch_barrier_async(queue, ^{
        [share addObject:@"xx"];
    });
    
}

#define NULL ((void*)0)
#define __DARWIN_NULL ((void*)0)
@end
