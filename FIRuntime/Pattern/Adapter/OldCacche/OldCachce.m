//
//  OldCachce.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/10.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "OldCachce.h"

@implementation OldCachce

- (void)old_saveCacheObject:(id)obj forKey:(NSString *)key{
    NSLog(@"saved cache by old cache object");
    
}

- (id)old_getCacheObjectForKey:(NSString *)key{
    NSString *obj = @"get cache by old cache object";
    NSLog(@"%@",obj);
    return obj;
}

@end
