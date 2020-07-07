//
//  CustomMode.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/29.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "CustomMode.h"

@implementation CustomMode

- (void)modeTestTimer {
    NSLog(@"mode:%@",[[NSRunLoop currentRunLoop] currentMode]);
}

/// 这里使用非主线程，主要考虑如果一直处于customMode模式，则主线瘫痪
- (void)runLoopModeTest {
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSTimer *tickTimer = [[NSTimer alloc] initWithFireDate:[NSDate date] interval:2 target:self selector:@selector(modeTestTimer) userInfo:nil repeats:YES];
        [[NSRunLoop currentRunLoop] addTimer:tickTimer forMode:@"customMode"];
        [[NSRunLoop currentRunLoop] runMode:@"customMode"  beforeDate:[NSDate distantFuture]];
    });
}

@end
