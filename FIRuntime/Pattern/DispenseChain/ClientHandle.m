//
//  ClientHandle.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/28.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "ClientHandle.h"
#import "ActionClickHandle.h"
#import "ActionClickEvent1.h"
#import "ActionClickEvent2.h"

@interface ClientHandle()

@property (nonatomic,assign) HandleType type;
@property (nonatomic,strong) ActionClickHandle *nextHandle;
@property (nonatomic,strong) ActionClickEvent1 *event1;
@property (nonatomic,strong) ActionClickEvent2 *event2;

@end

@implementation ClientHandle

- (instancetype)initWithType:(HandleType)type {
    if (self = [super init]) {
        _type = type;
        _event1 = [[ActionClickEvent1 alloc] init];
        _event1.type = ACTION_CLICK1;
        _event2 = [[ActionClickEvent2 alloc] init];
        _event2.type = ACTION_CLICK2;
        [_event1 setNextHandle:_event2];
        self.nextHandle = _event1;
    }
    return self;
}


- (void)handleClick {
    if (self.nextHandle.type==self.type) {
        [self.nextHandle handleClick];
    }else{
        while (self.nextHandle.type!=self.type) {
            self.nextHandle = self.nextHandle.nextHandle;
        }
        [self.nextHandle handleClick];
    }
}
        
@end
