//
//  Person.m
//  FIRuntime
//
//  Created by CSH on 2020/4/12.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Person.h"
#import "Car.h"
#import <objc/runtime.h>

@implementation Person

/**
 * 方法的本质是发送消息，发送消息会有以下几个流程。
 * 快速查找：（objc_msgSend)~cache_t 缓存消息。
 * 慢速查找：递归自己和父类~lookUpImpOrForward。
 * 查找不到消息：动态方法解析~resolveInstanceMethod。
 * 消息快速转发：forwardingTargetForSelector。
 * 慢速消息转发：methodSignatureForSelector&forwardInvocation。
 * 抛出异常：doesNotRecognizeSelector。
 * SEL是方法编号，在read_images时期就已经编译进内存。IMP是我们的函数实现指针。找IMP就是找函数的过程。
 */

/**
 * IMP动态方法
 */
void runResolve(id self, SEL _cmd) {
    NSLog(@"-- %@  %s", self, sel_getName(_cmd));
}

/**
 * 第一步实例方法动态解析，新增动态方法实现消息转发
 */
+ (BOOL)resolveInstanceMethod:(SEL)sel {
//    if (sel == @selector(run)) {
//        class_addMethod(self, sel, (IMP)runResolve, "v@:");
//        return YES;
//    }
    return [super resolveInstanceMethod:sel];
}

/**
 * 第二步消息快速转发，委托Car实例对象处理，.m文件实现run方法即可
 */
- (id)forwardingTargetForSelector:(SEL)aSelector {
    if (aSelector == @selector(run)) {
        return [[Car alloc] init];
    }
    return [super forwardingTargetForSelector:aSelector];
}

/**
 * 第三步生成方法签名
 */
- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    NSString *selector = NSStringFromSelector(aSelector);
    // 判断要转发的SEL
    if ([selector isEqualToString:@"run"]) {
        // 为要转发方法手动生成签名
        return [NSMethodSignature signatureWithObjCTypes:"v@:"];
    }
    return [super methodSignatureForSelector:aSelector];
}

/**
 * 关于生成签名的类型"v@:"解释一下。每一个方法会默认隐藏两个参数，self、_cmd，self代表方法调用者，_cmd代表这个方法的SEL，签名类型就是用来描述这个方法的返回值、参数的，v代表返回值为void，@表示self，:表示_cmd。
 */
- (void)forwardInvocation:(NSInvocation *)invocation {
    SEL selector = [invocation selector];
    // 新建需要转发消息的对象
    Car *car = [[Car alloc] init];
    if ([car respondsToSelector:selector]) {
        // 调用这个方法
        [invocation invokeWithTarget:car];
    }
}

@end
