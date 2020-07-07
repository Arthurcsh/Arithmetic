//
//  NewCachceProtocol.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/10.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NewCacheProtocol <NSObject>

- (void)new_saveCacheObject:(id)obj forKey:(NSString *)key;

- (id)new_getCacheObjectForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
