//
//  ActionClickHandle.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/28.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "ActionClickHandle.h"


@implementation ActionClickHandle

- (void)handleClick {
    // 公共逻辑处理
}

- (void)setNext:(id<ActionClickProtocol>)actionClickHandle {
    self.nextHandle = actionClickHandle;
}

@end
