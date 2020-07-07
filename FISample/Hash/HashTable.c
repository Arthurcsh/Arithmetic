//
//  HashTable.c
//  FISample
//
//  Created by chengshaohua on 2020/5/31.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "HashTable.h"

/**
 * 2. HashMap的存取实现
      既然是线性数组，为什么能随机存取？这里HashMap用了一个小算法，大致是这样实现：

     // 存储时:
     int hash = key.hashCode(); // 这个hashCode方法这里不详述,只要理解每个key的hash是一个固定的int值
     int index = hash % Entry[].length;
     Entry[index] = value;

     // 取值时:
     int hash = key.hashCode();
     int index = hash % Entry[].length;
     return Entry[index];
 */
