//
//  AdapterClient.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/10.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "AdapterClient.h"
#import "OldCacheProtocol.h"
#import "Adapter.h"
#import "NewCache.h"

@interface AdapterClient()

@property (nonatomic, strong) id<OldCacheProtocol>cache;

@end


@implementation AdapterClient


- (void)useOldCache {
    
    [self saveObject:@"cache" forKey:@"key"];
}

/**
 * 原接口不变，
 * 而之所以可以做到这么灵活，其实也是因为在一开始客户端只是依赖了旧缓存组件类所实现的接口，而不是旧缓存组件类的类型。有心的读者可能注意到了，上面``viewController``的属性是``@property (nonatomic, strong) id<OldCacheProtocol>cache;``。正因为如此，我们新建的适配器实例才能直接用在这里，因为适配器类也是实现了``<OldCacheProtocol>``接口。相反，如果我们的``cache``属性是这么写的：``@property (nonatomic, strong) OldCache *cache;``，即客户端依赖了旧缓存组件的类型，那么我们的适配器类就无法这么容易地放在这里了。因此为了我们的程序在将来可以更好地修改和扩展，依赖接口是一个前提。
 */
- (void)saveObject:(id)object forKey:(NSString *)key {
    
    [self.cache old_saveCacheObject:object forKey:key];
}

/**
 * 通过适配器转发新接口的方法
 * 适配器类也实现了旧缓存组件的接口；目的是让它也可以接收到客户端操作旧缓存组件的方法。
 * 然后，适配器的构造方法里面需要传入新组件类的实例；目的是在收到客户端操作旧缓存组件的命令后，将该命令转发给新缓存组件类，并调用其对应的方法。
 */
- (Adapter<OldCacheProtocol> *)cache {
    if (!_cache) {
        _cache = [[Adapter alloc] initWithNewCache:[[NewCache alloc] init]];
    }
    return _cache;
}

@end
