//
//  ActionClickHandle.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/28.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ActionClickProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, HandleType) {
    ACTION_CLICK1,
    ACTION_CLICK2,
};

@interface ActionClickHandle : NSObject<ActionClickProtocol>

@property (nonatomic,assign)HandleType type;
@property (nonatomic,strong)ActionClickHandle *nextHandle;

@end

NS_ASSUME_NONNULL_END
