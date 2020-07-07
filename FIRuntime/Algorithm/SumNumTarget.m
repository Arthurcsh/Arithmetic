//
//  SumNumTarget.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/2.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "SumNumTarget.h"

/**
 * 给定一个整数数组，找出其中两个数相加等于目标值
 * 给定数组及目标值 nums = [2,7,11,15] ,target = 9
 * 因为nums[0] + nums[1] = 2 + 7 = 9
 * 返回[0,1]
 */
@implementation SumNumTarget

/**
 * 时间复杂度O(n), 申请空间复杂度O(1)
 */
+ (NSArray *)sumNumber:(NSArray *)nums target:(NSInteger)target {
    NSMutableDictionary<NSNumber*, NSNumber*> *map = NSMutableDictionary.dictionary;
    NSMutableArray<NSNumber*> *result = [NSMutableArray arrayWithCapacity:2];
    
    for (int i=0;i<nums.count;i++) {
        NSInteger value = target - [nums[i] integerValue];
        if ([map.allKeys containsObject:@(value)]) {
            result[0] = @(i);
            result[1] = map[@(value)];
            break;
        }
        map[@(i)] = nums[i];
    }
    return result;
}


@end
