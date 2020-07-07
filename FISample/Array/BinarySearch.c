//
//  BinarySearch.c
//  FISample
//
//  Created by chengshaohua on 2020/5/9.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "BinarySearch.h"
#include <string.h>

/**
 * 对于已经排序的数组，用二分查找法查找K值对应的下标
 */
int binarySearch(int array[], int key) {
    int left = 0;
    int right = sizeof(*array) - 1;
    
    while (left <= right) {
        int pMid = (left + right) / 2;
        int vMid = array[pMid];
        if (key == vMid) {
            return pMid;
        } else if (key < vMid) {
            right = vMid - 1;
        } else {
            left = vMid + 1;
        }
    }
    return -1;
}

/**
 * 去除数组中重复的数字，返回新数组的长度 只用一次遍历时间复杂度O(n)
 */
int removeDuplicate(int nums[], int count) {
    int slow = 0;
    int fast = slow + 1;
    for (; fast<count; fast++) {
        if (nums[slow] != nums[fast]) {
            nums[++slow] = nums[fast];
        }
    }
    return slow + 1;
}

/**
 * 删除相邻相同的字符 (如: abbc -> ac    abccbdeffeg ->  adg)
 */
void removePairDuplicate(char *s) {
    int p;
    int q, c, len;
    c = s[0];  // 临时变量
    len = strlen(s);
    for (p = 1,q = 0;p<=len;p++) {
        if (s[p] == c) {
            c = q>0?s[--q]:s[++p];
        } else {
            s[q++] = c;
            c = s[p];
        }
    }
}
/**
 * 借用栈处理
 */
void removePairDuplicate2(char *s) {
    size_t len = strlen(s);
    char stack[len];
    int top = 0;
    char tov = s[0];
    int i;
    for (i=0;i<len;i++) {
        if (top > 0 && tov == s[i]) {
            top--;
        } else {
            stack[top++] = s[i];
            tov = s[i];
        }
    }
    printf("\n");
    for (i=0;i<top;i++) {
        printf("%c",stack[i]);
    }
    printf("\n");
}
void removePairDuplicate3(char str[]) {
    char *p=str,*q;
    while(*p) {
        for(q=p+1;*p==*q;q++);
        if(q==p+1) {
            *str++=*p++;
        } else p=q;
    }
    *str='\0';
}

/**
 * 合并两个有序数组
 */
void mergeListArray(int a[], int n, int b[], int k, int result[]) {
    int p = 0; int q = 0; int i = 0;
    
    while (p < n && q < k) {
        if (a[p] <= b[q]) {
            result[i] = a[p];
            p++;
        } else {
            result[i] = b[q];
            q++;
        }
        i++;
    }
    
    while (p < n) {
        result[i++] = a[p++];
    }
    while (q < k) {
        result[i++] = b[q++];
    }
}
void main_merge_list_array() {
    int a[5] = {3, 5, 6, 10, 12};
    int b[9] = {2, 4, 9, 11, 15, 19, 23, 34, 37};
    int result[5+9];
    mergeListArray(a, 5,b, 9, result);
    int i;
    for (i=0;i<14;i++) {
        printf("%d ",result[i]);
    }
    printf("\n");
}

/**
 * 在一个字符串中找到第一个只出现一次的字符（C）
 * 算法思路：字符（char）是一个长度为8的数据类型，因此总共有256种可能。
   每个字母根据ASCII码值作为数组的下标。数组中存储的是每个字符出现的次数。
 */
char find_once_char(char *string) {
    char result = '\0';
    
    int hash[256];
    int i;
    for (i=0;i<256;i++) {
        hash[i] = 0;
    }
    
    char *cur = string;
    while (*cur != '\0') {
        hash[*(cur++)]++;  // cur ASCII码为下标存储hash一次自增+1
    }
    
    cur = string;
    while (*cur != '\0') {
        if (hash[*cur] == 1) {
            result = *cur;   // 第一次出现一个字符的
            break;
        }
        cur++;
    }
    printf("once char: %c\n",result);
    return  result;
}


