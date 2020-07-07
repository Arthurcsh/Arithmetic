//
//  Observer.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Subject;

NS_ASSUME_NONNULL_BEGIN

@interface Observer : NSObject {
    
@protected Subject *_subject;
    
}

- (instancetype)initWithSubject:(Subject *)subject;

- (void)update;


@end

NS_ASSUME_NONNULL_END
