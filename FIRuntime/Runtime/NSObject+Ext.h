//
//  NSObject+Ext.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^DeallocBlock)(void);

/**
 * 分类-weak属性实现方式
 */
@interface NSObject (Ext)

@property (nonatomic, weak) id weakObj;
@property (nonatomic, copy) DeallocBlock block;

@end

NS_ASSUME_NONNULL_END
