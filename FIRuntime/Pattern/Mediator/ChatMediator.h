//
//  ChatMediator.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class MUser;

NS_ASSUME_NONNULL_BEGIN

@interface ChatMediator : NSObject

- (void)addUser:(MUser *)user;

- (void)sendMessage:(NSString *)message fromUser:(MUser *)user;

@end

NS_ASSUME_NONNULL_END
