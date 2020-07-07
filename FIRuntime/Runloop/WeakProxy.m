//
//  WeakProxy.m
//  FIRuntime
//
//  Created by CSH on 2020/4/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "WeakProxy.h"

@interface WeakProxy ()

@property (nonatomic, weak, readonly) id target;

@end

@implementation WeakProxy

- (instancetype)initWithTarget:(id)target {
    _target = target;
    return self;
}

+ (instancetype)proxyWithTarget:(id)target {
    return [[self alloc] initWithTarget:target];
}

// 备用接收者，这种方式也可以
- (id)forwardingTargetForSelector:(SEL)selector {
    return _target;
}

/**
 * 消息转发，方法签名
 */
- (NSMethodSignature *)methodSignatureForSelector:(SEL)sel {
    return [self.target methodSignatureForSelector:sel];
}

- (void)forwardInvocation:(NSInvocation *)invocation {
    SEL selector = [invocation selector];
    if ([self.target respondsToSelector:selector]) {
        [invocation invokeWithTarget:self.target];
    }
}

- (BOOL)respondsToSelector:(SEL)aSelector {
    return [self.target respondsToSelector:aSelector];
}

@end
