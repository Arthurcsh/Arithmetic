//
//  Backtrace.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/29.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Backtrace : NSObject

void registerSignalHandler(void);

@end

NS_ASSUME_NONNULL_END
