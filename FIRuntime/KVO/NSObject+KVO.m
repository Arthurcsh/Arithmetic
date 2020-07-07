//
//  NSObject+KVO.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/7/1.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "NSObject+KVO.h"
#import "ObserverHelper.h"
#import <objc/runtime.h>


/**
 * 对象销毁自动释放target
 */
@interface __DeallocCallback : NSObject {
    @public
    char _key;
}
@property (nonatomic, unsafe_unretained, nullable) id target;
@property (nonatomic, copy, nullable) DeallocCallbackTask task;

@end

@implementation __DeallocCallback

- (void)dealloc {
    if (_task) _task(_target);
}

@end

@implementation NSObject (DeallocCallback)

- (void)csh_addDeallocCallbackTask:(DeallocCallbackTask)blockTask {
    __DeallocCallback *callback = [__DeallocCallback new];
    callback.target = self;
    callback.task = blockTask;
    objc_setAssociatedObject(self, &callback->_key, callback, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end


@implementation NSObject (KVO)

- (void)invoke_addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath {
    [self invoke_addObserver:observer forKeyPath:keyPath ontext:nil];
}

- (void)invoke_addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath ontext:(nullable void *)context {
    [self invoke_addObserver:observer forKeyPath:keyPath options:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew context:context];
}

- (void)invoke_addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context {
    NSParameterAssert(observer);
    NSParameterAssert(keyPath);
    if (!observer || !keyPath) return;
    
    NSString *hashstr = [NSString stringWithFormat:@"%lu-%@", (unsigned long)[observer hash], keyPath];
    @synchronized (self) {
        if ( [[self observerhashSet] containsObject:hashstr] ) return;
        else [[self observerhashSet] addObject:hashstr];
    }
    
    [self addObserver:observer forKeyPath:keyPath options:options context:context];
    
    ObserverHelper *helper = [ObserverHelper new];
    ObserverHelper *sub = [ObserverHelper new];
    
    sub.target = helper.target = self;
    sub.observer = helper.observer = observer;
    sub.keyPath = helper.keyPath = keyPath;
    
    // 互相 weak 引用
    helper.factor = sub;
    sub.factor = helper;
    
    __weak typeof(self) _self = self;
    [observer csh_addDeallocCallbackTask:^(id  _Nonnull obj) {
        __strong typeof(_self) self = _self;
        if (!self ) return;
        @synchronized (self) {
            [[self observerhashSet] removeObject:hashstr];
        }
    }];
    
    const char *helperKey = [NSString stringWithFormat:@"%zd", [observer hash]].UTF8String;
    objc_setAssociatedObject(self, helperKey, helper, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(observer, helperKey, sub, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSMutableSet<NSString *> *)observerhashSet {
    NSMutableSet<NSString *> *set = objc_getAssociatedObject(self, _cmd);
    if ( set ) return set;
    set = [NSMutableSet set];
    objc_setAssociatedObject(self, _cmd, set, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    return set;
}

@end
