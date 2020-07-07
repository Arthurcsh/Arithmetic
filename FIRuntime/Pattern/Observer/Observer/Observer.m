//
//  Observer.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Observer.h"
#import "Subject.h"

@implementation Observer

- (instancetype)initWithSubject:(Subject *)subject {
    if (self = [super init]) {
        _subject = subject;
        [_subject addObserver:self];
    }
    
    return self;
}

- (void)update {
    
    NSLog(@"implementation by subclasses");
}


@end
