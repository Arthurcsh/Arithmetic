//
//  ClientHandle.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/28.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ActionClickProtocol.h"
#import "ActionClickHandle.h"

NS_ASSUME_NONNULL_BEGIN

@interface ClientHandle : NSObject

- (instancetype)initWithType:(HandleType)type;

- (void)handleClick;


@end

NS_ASSUME_NONNULL_END
