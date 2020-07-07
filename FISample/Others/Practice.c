//
//  Practice.c
//  FISample
//
//  Created by chengshaohua on 2020/5/16.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "Practice.h"
#include <stdbool.h>

/**
 * 要将"China"译成密码，译码规律是：用原来字母后面的第4个字母代替原来的字母．
   例如，字母"A"后面第4个字母是"E"．"E"代替"A"。因此，"China"应译为"Glmre"。
 */
void charTransfer() {
    char chars[] = "China";
    for (int i=0; i<5; i++) {
        printf("%c", chars[i]+4);
    }
    printf("\n");
}

/**
 * 输入一个华氏温度，要求输出摄氏温度。公式为 c=5(F-32)/9，取位2小数。
 */
void outTemp() {
    float temp;
    scanf("%f", &temp);
    float result = 5*(temp - 32)/9;
    
    printf("Out: %.2f", result);
}

/**
 * 输入圆半径，输出圆面积
 */
void circularArea() {
    const double PI = 3.1415;
    float circular;
    scanf("%f", &circular);
    printf("%.2f", PI * circular * circular);
}

/**
 * 输入宽和高，输出正方形面积
 */
void rectangleArea() {
    float widht, height;
    scanf("%f %f", &widht, &height);
    printf("C:%f\nS:%f", 2*(widht+height), widht*height);
}

/**
* 三个数找最大值-题解(C语言代码)
*/
void maxNumber() {
    int a, b, c;
    scanf("%d %d %d", &a,&b,&c);
    
    int max = a>b?a:b;
    max = max<c?c:max;
    printf("%d", max);
}

/**
 * 三个数找最大值-题解(C语言代码) 用递归
 */
int recursiveMax(int nums[], int L, int R) {
    if (L == R) {
        return nums[L];
    }else {
        int left = nums[L];
        int max = recursiveMax(nums, (L+1), R);
        
        return max>left?max:left;
    }
}

/**
 *  有一个函数
     y={ x      x<1
         | 2x-1   1<=x<10
         \ 3x-11  x>=10

     写一段程序，输入x，输出y
 */
void devideFunction() {
    float x, y;
    scanf("%f", &x);
    if (x<1) {
        y = x;
    }else if(x>=10) {
        y = 3*x-11;
    }else {
        y = 2*x-1;
    }
    printf("%f", y);
}

#define swap(m,n) {int t;t=m;m=n;n=t;}
/**
 * 输入三个整数，按由小到大的顺序输出。
 */
void sortNumber() {
    int num[3], k;
    scanf("%d %d %d", &num[0], &num[1], & num[2]);
    
    // 冒泡排序
    for (int i=0; i<3; i++) {
        for (int j=i+1; j<3; j++) {
            if (num[i]>num[j]) {
                k = num[i];
                num[i] = num[j];
                num[j] = k;
            }
        }
    }
    printf("%d %d %d\n", num[0],num[1],num[2]);
}

/**
 * 给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。 90分以及90分以上为A，80-89分为B，70-79分为C，60-69分为D，60分以下为E。
 */
void gradeNumber() {
    int grade;
    char result;
    scanf("%d", &grade);
    
    if (grade >= 90) {
        result = 'A';
    }else if (grade>=80 && grade<90) {
        result = 'B';
    }else if (grade>=70 && grade<80) {
        result = 'C';
    }else if (grade>=60 && grade<70) {
        result = 'D';
    }else {
        result = 'E';
    }
    printf("%c", result);
}

/**
 * 数字处理与判断: 给出一个不多于5位的整数，
 * 要求 1、求出它是几位数
 * 2、分别输出每一位数字
 * 3、按逆序输出各位数字，例如原数为321,应输出123
 */
void sortNumbers() {
    int n,count=0, x[5];    //count统计位数，x[5]储存数字
    for (n=0;n<5;n++) {
        int temp = getchar();   //temp临时储存数字字符的ASCII码
        if (temp==10) break;    //输入换行\n后跳出for循环
        
        count++;
        x[n] = temp - 48;       //字符0的ASCII码是48
    }
    printf("%d\n", count);
    
    for (n=0; n<count; n++) {
        printf("%d ",x[n]);
    }
    printf("\n");
    for (n=count-1; n>=0; n--) {
        printf("%d",x[n]);
    }
    printf("\n");
}

// 字符串转数值
int string_atoi(const char *src) {
    int s = 0;
    bool isMinus = false;
    
    // 跳过空白
    while (*src == ' ') {
        src++;
    }
    
    if (*src == '+' || *src == '-') {
        if (*src == '-') {
            isMinus = true;
        }
        src++;
    } else if (*src<'0' || *src>'9') {
        s = 2147483647;   //如果第一位既不是符号也不是数字，直接返回异常值
        return s;
    }
    
    while (*src != '\0' && *src >= '0' && *src <= '9') {
        s = s * 10 + *src - '0';
        src++;
    }
    
    int result = s*(isMinus?-1:1);
    printf("atoi: %d\n", result);
    
    return result;
}

// 数组转字符串
int string_itoa(int n, char s[]) {
    int sign;
    
    sign = n; // 记录符号
    if (sign<0) {
        n = -n;
    }
    
    int i = 0;
    do {
        s[i++] = n % 10 + '0';  // 取下一个数字
    } while ((n /= 10) > 0); // 删除该数字
    
    if (sign < 0) {
        s[i++] = '-';
        s[i] = '\0';
    }
    printf("itoa: %s\n", s);
    
    return 0;
}

// 左旋转字符串与翻转字符串中单词顺序的方法, 时间复杂度为 O(n)，内存为 O(1）
void string_reverse(char a[], int low, int high) {
    while (low < high) {
        char tmp = a[low];
        a[low++] = a[high];
        a[high--] = tmp;
    }
}

// 查找第index前后部分字符串段逆序
void string_index(char a[], int n, int index) {
    string_reverse(a, 0, index-1);   // 先0～index部分逆序
    string_reverse(a, index, n-1);   // 再index~n部分逆袭
    string_reverse(a, 0, n-1);       // 最后整体逆序
    
    int i;
    for (i = 0;i<n;i++) {
        printf("%c", a[i]);
    }
    printf("\n");
}

// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
int sub_string_maxLength(char *s) {
    int i;
    int max = 0;
    int left = 0;// 左边窗口的边界
    int table[256];
    int tmp = 0;
    int len = strlen(s);
    
    for(i = 0;i<256;i++){
        table[i]=-1;
    }

    for(i = 0; i < len; i++) {// 控制的是右边窗口的边界
        int index = s[i];
        if(left <= table[index] && table[index] <= i) { // 判断是否发生的重复字符
            left = table[index]+1; // 更新左边窗口的边界值
        }

        tmp = i-left+1; // 计算当前滑动窗口的大小
        max = tmp>max?tmp:max;// 更新最大子串长度
        table[index] = i; // 记录当前字符在字符串中的下标
    }

    return max;
}


