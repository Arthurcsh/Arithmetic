//
//  MUser.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "MUser.h"

@implementation MUser {
    NSString *_name;
    ChatMediator *_chatMediator;
}

- (instancetype)initWithName:(NSString *)name mediator:(ChatMediator *)mediator {
    if (self = [super init]) {
        _name = name;
        _chatMediator = mediator;
    }
    return self;
}

- (void)sendMessage:(NSString *)message {
    NSLog(@"================");
    NSLog(@"%@ sent message:%@",_name,message);
    [_chatMediator sendMessage:message fromUser:self];
}

- (void)receivedMessage:(NSString *)message {
    NSLog(@"%@ has received message:%@",_name,message);
}

@end
