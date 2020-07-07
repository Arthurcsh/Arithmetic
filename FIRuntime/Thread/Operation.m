//
//  Operation.m
//  FIRuntime
//
//  Created by CSH on 2020/4/27.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Operation.h"

/**
 * 任务执行状态：
 * 1. isReady
 * 2. isExecuting
 * 3. isFinishing
 * 4. isCancelled
 */

/**
 * 如果只重写main方法，底层控制变更任务执行完成状态，以及任务退出。
 * 如果重写start方法，自行控制任务状态。
 */
@implementation Operation

@end
