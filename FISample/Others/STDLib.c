//
//  STDLib.c
//  FISample
//
//  Created by chengshaohua on 2020/5/19.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "STDLib.h"
#include <string.h>
#include <stdio.h>

/**
 * strcpy()对于字符串进行拷贝，必须保证dest足够大能够容纳source，否则导致溢出错误
 */
void stringSourceCopy() {
    char dest[50] = {0};
    char src[50] = {"http://www.baidu.com"};
    strcpy(dest, src);
    puts(dest);
}

/**
 * 字符串长度
 */
void stringLength() {
    char arr[] = "admin";
    char str[100] = { 0 };
    gets(str);
    size_t length = strlen(str);
    
    printf("Length: %ld\n", length);
    printf("Sizeof: %ld\n", sizeof(arr));
}

/**
 * 求字符串互补跨度（长度） size_t strcspn(const char* str, const char* reject) 函数用来返回从字符串 str 开头算起，连续有几个字符都不在 reject 中；也就是说，str 中连续有几个字符和 reject 没有交集。
 * 换个角度看，strcspn() 返回的是 str 中第一次出现 reject 中字符的位置。
 */
void stringCspan() {
    char str[] = {"http://c.biancheng.net"};
    char keys[50] = { "?.,:\"\'-!" };
    int index = (int)strcspn(str, keys);
    printf("First punctuation in str is at position %d. \n", index);
}

/**
 *  strcmp() 函数用于对两个字符串进行比较（区分大小写）
 *  strcmp() 会根据 ASCII 编码依次比较 str1 和 str2 的每一个字符，直到出现不到的字符，或者到达字符串末尾（遇见\0）
 */
void stringCompare() {
    char str1[50] = {0};
    char str2[50] = {0};
    
    int index = 1;
    do {
        printf("---第%d次输入---\n", index);
        gets(str1);
        gets(str2);
        index++;
    } while (strcmp(str1, str2));
}

/**
 * char* strchr(const char* str, int c)
 * strchr() 函数用于查找给定字符串中某一个特定字符。
 * 函数会依次检索字符串 str 中的每一个字符，直到遇见字符 c，或者到达字符串末尾（遇见\0）。
 * 返回值：返回在字符串 str 中第一次出现字符 c 的位置，如果未找到该字符 c 则返回 NULL。
 */
void stringQuery() {
    const char *str = "http://ifeng.com";
    int index = 'f';
    char *position = strchr(str, index);
    
    if (position) {
        printf("Found: %c\n", *position);
    } else {
        puts("Not Found\n");
    }
}

/**
 * char*strcat(char* strDestination, const char* strSource);
 * strcat() 函数用来将两个字符串连接（拼接）起来
 * strcat() 函数把 strSource 所指向的字符串追加到 strDestination 所指向的字符串的结尾，所以必须要保证 strDestination 有足够的内存空间来容纳两个字符串，否则会导致溢出错误。
 */
void stringContact() {
    char str1[50] = {0};
    char str2[50] = {0};
    gets(str1);
    gets(str2);
    strcat(str1, str2);
    puts(str1);
}

#include "ctype.h"
/**
 * int isupper(int c);
 * isupper() 函数用来判断一个字符是否是大写字母
 * 返回值：返回值为非 0（真）表示 c 是大写字母，返回值为 0（假）表示 c 不是大写字母。
 *
 * islower() 函数用来判断一个字符是否是小写字母
 */
void stringIsupper() {
    int index = 0;
    const char str[] = "C++ Java Python C# Linux Golang Shell\n";
    char cha;
    
    while (str[index]) {
        cha = str[index];
        if (isupper(cha)) {
            cha = tolower(cha);
        }
        putchar(cha);
        index++;
    }
}

/**
 * int isspace(int c);
 * isspace() 函数用来检测一个字符是否是空白符。在默认情况下，空白符包括：
 * 字符    ASCII码 (十六进制)    说明 (缩写)
    ' '    0x20    空格 (SPC)
    '\t'    0x09    水平制表符 (TAB)
    '\n'    0x0a    换行符 (LF)
    '\v'    0x0b    垂直制表符 (VT)
    '\f'    0x0c    换页 (FF)
    '\r'    0x0d    回车 (CR)
   返回值：返回值为非 0（真）表示c是空白符，返回值为 0（假）表示c不是空白符。
 */
void stringIsspace() {
    const char str[] = "Linux C++\tPython Shell\nC# Java\n";
    int index = 0;
    char cha;
    while (str[index]) {
        cha = str[index];
        if (isspace(cha)) {
            cha = '\n';
        }
        putchar(cha);
        index++;
    }
}

/**
 * int isprint(int c);
 * isprint() 函数用来检测一个字符是否是可打印字符（Printable Character）
 * 返回值：返回值为非 0（真）表示 c 是可打印字符，返回值为 0（假）表示 c 不是可打印字符
 */
void stringIsprint() {
    int i=0;
    char str[]="C++ Java \n C# Python \t Shell Linux\n";
    while(str[i]) {
        if(isprint(str[i])) putchar (str[i]);
        i++;
    }
    printf("\n");
}
