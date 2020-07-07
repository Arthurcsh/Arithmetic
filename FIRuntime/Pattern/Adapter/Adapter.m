//
//  Adapter.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/10.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Adapter.h"
#include "NewCache.h"

@implementation Adapter {
    NewCache *_newCache;
}

- (instancetype)initWithNewCache:(NewCache *)newCache {
    if (self = [super init]) {
        _newCache = newCache;
    }
    return self;
}

- (void)old_saveCacheObject:(id)obj forKey:(NSString *)key {
    if (!_newCache) return;
    
    [_newCache new_saveCacheObject:obj forKey:key];
}

- (id)old_getCacheObjectForKey:(NSString *)key {
    return [_newCache new_getCacheObjectForKey:key];
}


@end
