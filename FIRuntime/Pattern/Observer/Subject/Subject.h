//
//  Subject.h
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Observer;

NS_ASSUME_NONNULL_BEGIN

@interface Subject : NSObject {
    
@protected float _buyingPrice;
@protected NSMutableArray<Observer *> *_observers;
    
}

- (void)addObserver:(Observer *) observer;


- (void)removeObserver:(Observer *) observer;


- (void)notifyObservers;


- (void)setBuyingPrice:(float)price;


- (double)getBuyingPrice;

@end

NS_ASSUME_NONNULL_END
