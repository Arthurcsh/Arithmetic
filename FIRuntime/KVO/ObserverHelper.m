//
//  ObserverHelper.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/7/1.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "ObserverHelper.h"

@implementation ObserverHelper

- (void)dealloc {
    if (_factor) {
        [_target removeObserver:_observer forKeyPath:_keyPath];
        _factor = nil;
    }
}



@end
