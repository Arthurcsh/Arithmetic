//
//  ObserverClient.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "ObserverClient.h"
#import "Investor.h"
#import "FinancialAdviser.h"


@implementation ObserverClient

- (void)observerWithSubject {
    FinancialAdviser *financial = [[FinancialAdviser alloc] init];
    
    Investor *iv1 = [[Investor alloc] initWithSubject:financial];
    
    NSLog(@"====== first advice ========");
    [financial setBuyingPrice:1.3];
    
    
    Investor *iv2 = [[Investor alloc] initWithSubject:financial];
    Investor *iv3 = [[Investor alloc] initWithSubject:financial];

    NSLog(@"====== second advice ========");
    [financial setBuyingPrice:2.6];
}

@end
