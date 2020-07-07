//
//  MediatorClient.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "MediatorClient.h"
#import "MUser.h" 
#import "ChatMediator.h"

@implementation MediatorClient

- (void)mediatorWithUser {
    ChatMediator *cm = [[ChatMediator alloc] init];
    
    MUser *user1 = [[MUser alloc] initWithName:@"Jack" mediator:cm];
    MUser *user2 = [[MUser alloc] initWithName:@"Bruce" mediator:cm];
    MUser *user3 = [[MUser alloc] initWithName:@"Lucy" mediator:cm];
    
    [cm addUser:user1];
    [cm addUser:user2];
    [cm addUser:user3];
    
    [user1 sendMessage:@"happy"];
    [user2 sendMessage:@"new"];
    [user3 sendMessage:@"year"];
}

@end
