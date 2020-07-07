//
//  CharReverse.m
//  FIRuntime
//
//  Created by CSH on 2020/4/28.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "CharReverse.h"

@implementation CharReverse

void char_reverse(char* cha) {
    // 指向第一个字符
    char *begin = cha;
    char *end = cha + strlen(cha) - 1;
    
    while (begin < end) {
        // 交换前后两个字符，同时移动指针
        char temp = *begin;
        *(begin++) = *end;
        *(end--) = temp;
    }
}


@end
