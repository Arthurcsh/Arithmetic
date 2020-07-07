//
//  ObserverHelper.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/7/1.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ObserverHelper : NSObject

@property (nonatomic, unsafe_unretained) id target;     // 监听对象
@property (nonatomic, unsafe_unretained) id observer;   // 观察者
@property (nonatomic, copy) NSString *keyPath;
@property (nonatomic, weak) ObserverHelper *factor;

@end

NS_ASSUME_NONNULL_END
