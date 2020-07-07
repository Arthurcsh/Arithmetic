//
//  MUser.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ChatMediator.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 用户类在初始化的时候需要传入中介者的实例，并持有。目的是为了在后面发送消息的时候把消息转发给中介者。
 另外，用户类还对外提供了发送消息和接收消息的接口。而在发送消息的方法内部其实调用的是中介者的发送消息的方法（因为中介者持有了所有用户的实例，因此可以做多路转发）
 */
@interface MUser : NSObject

- (instancetype)initWithName:(NSString *)name mediator:(ChatMediator *)mediator;

- (void)sendMessage:(NSString *)message;

- (void)receivedMessage:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
