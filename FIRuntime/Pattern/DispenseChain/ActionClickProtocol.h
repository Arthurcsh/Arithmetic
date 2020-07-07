//
//  ActionClickProtocol.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/28.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ActionClickProtocol <NSObject>

- (void)handleClick;
- (void)setNext:(id<ActionClickProtocol>)actionClickHandle;

@end

NS_ASSUME_NONNULL_END
