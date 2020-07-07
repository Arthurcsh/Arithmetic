//
//  Adapter.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/10.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OldCacheProtocol.h"

@class NewCache;

NS_ASSUME_NONNULL_BEGIN

@interface Adapter : NSObject <OldCacheProtocol>

- (instancetype)initWithNewCache:(NewCache *)newCache;

@end

NS_ASSUME_NONNULL_END
