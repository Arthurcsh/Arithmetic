//
//  UIButton+AntiRepeat.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "UIButton+AntiRepeat.h"
#import <objc/runtime.h>

static NSString *TIME_INTERVAL = @"time.interval";
static NSString *IS_SELECT = @"is.select";
static int DEFAULT_INTERVAL = 2;

@implementation UIButton (AntiRepeat)

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [self exchangeClickButton];
    });
}

+ (void)exchangeClickButton {
    SEL selOringin = @selector(sendAction:to:forEvent:);
    SEL selRepeat = @selector(invokeSendAction:to:forEvent:);
    /*
    class_getMethodImplementation(__unsafe_unretained Class cls, <#SEL name#>) 获取实现方法(IMP实现方法)
    class_getClassMethod  :获取类方法
    class_getInstanceMethod: 获取对象方法
    */

    Method methodOringin = class_getInstanceMethod(self, selOringin);
    Method methodInvoke = class_getInstanceMethod(self, selRepeat);

    //讲 methodB 的实现 添加到系统方法中  也就是说 讲 methodA方法指针添加成 方法methodB  返回值表示是否添加成功
    BOOL isAdd = class_addMethod(self, selOringin, method_getImplementation(methodInvoke), method_getTypeEncoding(methodInvoke));
    //添加成功了 说明 本类中不存在methodB 所以此时此刻必须将方法b的实现指针换成方法A的，否则b方法将没有实现
    if (isAdd) {
        class_replaceMethod(self, selRepeat, method_getImplementation(methodOringin), method_getTypeEncoding(methodOringin));
    } else {
        method_exchangeImplementations(methodOringin, methodInvoke);
    }
}

/**
 * 当按钮点击执行 sendAction 时，将会执行invokeSendAction
 */
- (void)invokeSendAction:(SEL)action to:(id)target forEvent:(UIEvent*)event {
    if ([NSStringFromClass(self.class) isEqualToString:@"UIButton"]) {
        self.timeInterval = (self.timeInterval!=0)?:DEFAULT_INTERVAL;
        if (self.isSelect) {
            return;
        } else if(self.timeInterval>0) {
            [self performSelector:@selector(resetState) withObject:nil afterDelay:self.timeInterval];
        }
    }
    self.isSelect = YES;
    [self invokeSendAction:action to:target forEvent:event];
}

- (void)resetState {
    [self setIsSelect:NO];
}

- (NSTimeInterval)timeInterval {
    return [objc_getAssociatedObject(self, &TIME_INTERVAL) doubleValue];
}

- (void)setTimeInterval:(NSTimeInterval)timeInverval {
    objc_setAssociatedObject(self, &TIME_INTERVAL, @(timeInverval), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (BOOL)isSelect {
    return [objc_getAssociatedObject(self, &IS_SELECT) boolValue];
}

- (void)setIsSelect:(BOOL)isSelect {
    objc_setAssociatedObject(self, &IS_SELECT, @(isSelect), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end
