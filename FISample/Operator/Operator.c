//
//  Operator.c
//  FISample
//
//  Created by chengshaohua on 2020/6/9.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "Operator.h"

/**
 * 请实现一个函数，属于一个整数，输出该数二进制表示中1的个数，例如把9表示成二进制是1001，有2位为1。因此如果输入9，该函数输出2。
 */
int numberOf(int number) {
    int count = 0;
    while ( number != 0) {
        ++count;
        // 从最右边的1开始，每一次操作都使n的最右的一个1变成了0, 即使是符号位也会进行操作
        number = number & (number - 1);
    }
    return count;
}

/**
 * 在一个整数数组中，除了一个数之外，其他的数出现的次数都是两次，求出现一次的数，要求时间复杂度尽可能的小。
 * 例如数组{1,2,2,3,3,6,6},出现一次的数是1.
 */
int numberAppearOnce(int number[], int n) {
    if (n <= 2) {
        printf("数组长度必须大于2. ");
        return -1;
    }
    int result = 0;
    int i;
    for (i=0;i<n;i++) {
        result ^= number[i];
    }
    return result;
}

/*
 * RLE压缩算法
 */
char *stringPress(char *source) {
    char *buffer;
    int i;
    
    return buffer;
}

/*
 public static String compress(String source) {
     if (source.length() <= 1) return source;

     int runLength = 1;
     while (runLength < source.length() && source.charAt(0) == source.charAt(runLength)) {
         runLength++;
     }

     String lengthString = runLength > 1 ? String.valueOf(runLength) : "";
     return lengthString + source.substring(0,1) + compress(source.substring(runLength));
 }
 */
