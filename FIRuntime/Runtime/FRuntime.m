//
//  FRuntime.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "FRuntime.h"
#import <objc/runtime.h>

@interface FRuntime () {
    NSString *name;
}

@property (nonatomic, copy) NSString *_address;

@end

@implementation FRuntime

- (instancetype)init {
    if (self = [super init]) {
        name = @"cheng";
        __address = @"shanghai";
    }
    return self;
}


/**
 * 属性与变量，类信息，
 * 1. runtime提供大量函数来操作类与对象，类操作大部分以class为前缀，
 * 2. 对象操作方法大部分是以objc或object_为前缀
 */
- (void)testClassAndMeta {
    // 类名操作函数
    Class current = [self class];
    const char *clazzName = class_getName(current);
    Class superClazz = class_getSuperclass(current);
    printf("class name: %s\n", clazzName);
    NSLog(@"super class: %@", superClazz);
    
    // Meta元类操作
    Class metaClazz = objc_getMetaClass(clazzName);
    Class metaObjc = objc_getMetaClass(clazzName);
    NSLog(@"meta class: %@  meta objc: %@", metaClazz, metaObjc);
    
    BOOL isMeta = class_isMetaClass(metaClazz);
    NSLog(@"is Meta: %@", isMeta?@"YES":@"NO");
    
    // 实例变量大小
    size_t class_size = class_getInstanceSize(current);
    NSLog(@"class size: %ld", class_size);
}

- (void)testIVarProperty {
    Class current = [self class];
    const char *clazzName = class_getName(current);
    Ivar ivar = class_getInstanceVariable(current, "_address");
    id getIvar = object_getIvar(self, ivar);
    
    NSLog(@"--- ivar: %@",getIvar);
    
    // 成员变量及属性
    
//    class_getProperty([self class], 0);
    
}

- (void)addClassMethod {
    Class newClass = objc_allocateClassPair([self class], "FSubClass", 0);
    class_addMethod(newClass, @selector(subClassMethod), (IMP)FClassMethod, "v@:");
    objc_registerClassPair(newClass);
    
    id instance = [[newClass alloc] init];
    [instance performSelector:@selector(subClassMethod)];
}

void FClassMethod(id self, SEL _cmd) {
    NSLog(@"-- %@", class_getSuperclass([self class]));
}

@end
