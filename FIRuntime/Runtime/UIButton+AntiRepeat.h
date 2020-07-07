//
//  UIButton+AntiRepeat.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 按钮防重点击
 */
@interface UIButton (AntiRepeat)

@property (nonatomic, assign) NSTimeInterval timeInterval;
@property (nonatomic, assign) BOOL isSelect;

@end

NS_ASSUME_NONNULL_END
