//
//  Subject.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Subject.h"
#import "Observer.h"

@implementation Subject

- (instancetype)init {
    if (self = [super init]) {
        _observers = [NSMutableArray array];
    }
    return self;
}

- (void)addObserver:(Observer *) observer {
    [_observers addObject:observer];
}


- (void)removeObserver:(Observer *) observer {
    [_observers removeObject:observer];
}


- (void)notifyObservers {
    for (Observer * observer in _observers) {
        [observer update];
    }
}


- (void)setBuyingPrice:(float)price {
    _buyingPrice = price;
    
    [self notifyObservers];
}


- (double)getBuyingPrice {
    
    return _buyingPrice;
}

@end
