//
//  BlockForwarding.m
//  FIRuntime
//
//  Created by CSH on 2020/4/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "BlockForwarding.h"

@interface BlockForwarding ()
@property (nonatomic, copy) int(^blk)(int);

@end


@implementation BlockForwarding

- (void)initBlock {
    __block int multiplier = 10;
    _blk = ^int(int num) {
        return num * multiplier;
    };
    
    multiplier = 6;
    [self executeBlock];
}

- (void)executeBlock {
    int result = _blk(4);
    NSLog(@"result is %d", result);
}


@end
