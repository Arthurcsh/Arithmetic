//
//  Investor.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/20.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Investor.h"
#import "Subject.h"

@implementation Investor

- (void)update {
    
    float buyingPrice = [_subject getBuyingPrice];
    NSLog(@"investor %p buy stock of price:%.2lf",self,buyingPrice);
}

@end
