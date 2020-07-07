//
//  DupllcatesPoint.m
//  FIRuntime
//
//  Created by CSH on 2020/4/17.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "DupllcatesPoint.h"

@implementation DupllcatesPoint

/*
 *快慢指针：给定任意一个有序数组，计算出去重后的数组长度
 *要求：只能在原数组中进行更改
 */
+ (int)removeDupllcates:(NSMutableArray*)nums {
    if (nums.count==0) return 0;
    
    int slow = 0;
    for (int fast=0; fast<nums.count; fast++) {
        if (nums[slow] != nums[fast]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    NSLog(@"--- slow: %d， result: %@", slow, nums);
    return slow+1;
}

+ (int)solutionDupllcates:(NSMutableArray*)nums {
    int slow = 0, fast = 0;
    
    while (true) {
        fast++;  // 快指针向右移动
        
        // 快指针移动到数组末尾则退出，说明数组元素完成判断去重
        if (fast >= nums.count) {
            break;
        }
        if (nums[fast] == nums[slow]) {
            continue;  // 慢指针与快指针指向元素相同，说明重复元素；快指针继续向h右移动。
        } else {
            // 慢指针与快指针指向元素不同；则将快指针元素复制到慢指针后一位，这样b就保证慢指针后元素不重复
            nums[slow+1] = nums[fast];
            slow++;  // 慢指针向右继续移动；
        }
    }
    NSLog(@"--- slow: %d， result: %@", slow, nums);
    return slow + 1;
}

@end
