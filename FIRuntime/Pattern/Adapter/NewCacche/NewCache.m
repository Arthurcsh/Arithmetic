//
//  NewCachce.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/10.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "NewCache.h"

@implementation NewCache

- (void)new_saveCacheObject:(id)obj forKey:(NSString *)key{
    
    NSLog(@"saved cache by new cache object");
}

- (id)new_getCacheObjectForKey:(NSString *)key{
    
    NSString *obj = @"saved cache by new cache object";
    NSLog(@"%@",obj);
    return obj;
}

@end
