//
//  ChatMediator.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "ChatMediator.h"
#import "MUser.h"

@implementation ChatMediator {
    NSMutableArray <MUser *> *_userList;
}

- (instancetype)init {
    if (self = [super init]) {
        _userList = NSMutableArray.array;
    }
    
    return self;
}

- (void)addUser:(MUser *)user{

    [_userList addObject:user];
}

- (void)sendMessage:(NSString *)message fromUser:(MUser *)user{
    [_userList enumerateObjectsUsingBlock:^(MUser * iterUser, NSUInteger idx, BOOL * stop) {
        if (iterUser != user) {
            [iterUser receivedMessage:message];
        }
    }];
}

@end
