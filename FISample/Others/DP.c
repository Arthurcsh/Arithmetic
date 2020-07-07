//
//  DP.c
//  FISample
//
//  Created by chengshaohua on 2020/5/28.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "DP.h"
#include <stdlib.h>
#include <math.h>

/**
 * 一个整数数组中的元素有正有负，在该数组中找出一 个连续子数组，要求该连续子数组中各元素的和最大，这个连续子数组便被称作最大连续子数组。比如数组{2,4,-7,5,2,-1,2,-4,3}的最大连续子数组为{5,2,-1,2}，最大连续子数组的和为5+2-1+2=8。问题输入就是一个数组，输出该数组的“连续子数组的最大和”。
 *
 * 递推公式是DP[i] = max{DP[i-1] + A[i],A[i]}；既然转移方程出来了，意味着写一层循环就可以解决这个问题。
   将这个转移方程变为形象的if-else判断
 */
int MaxSubSum(int arr[],int len) {
    int i = 0, j;
    int begin = -1, end = -1;
    int MaxSum = 0;
    int ThisSum= 0;
    for (j=i;j<len;j++) {
        ThisSum += arr[j];
        if(ThisSum > MaxSum) {
            MaxSum = ThisSum;
            begin = i; end = j;
        }
            
        /*如果累加和出现小于0的情况，
           则和最大的子序列肯定不可能包含前面的元素，
           这时将累加和置0，从下个元素重新开始累加  */
        else if(ThisSum < 0) {
            i = j + 1; // 修改起点位置
            ThisSum = 0;
        }
    }
    printf("begin: %d  end: %d\n", begin,end);
    printf("Max subsum: %d\n", MaxSum);
    return MaxSum;
}

int MaxsumUlt(int * arr, int size) {
    int maxSum = 0xf0000000;
    int sum = 0;
    int i;
    for(i = 0; i < size; ++i) {
        if(sum < 0) {
            sum = arr[i];
        } else {
            sum += arr[i];
        }
        if(sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

/**
 * 暴力递归
 * 求数组最长相隔元素最大值
 * a数组， idx下标
 * 返回最长相隔元素最大值
 */
int solver(int a[], int idx) {
    if (idx < 0) return 0;
    
    // 从数组后面开始
    int interval = a[idx] + solver(a, idx-2);
    int single = solver(a, idx-1);
    int max = interval>single?interval:single;
    
    return max;
}

int robber(int a[], int n) {
    int max = solver(a, n-1);
    printf("max: %d\n", max);
    return max;
}

/**
 * 菲波那契数列(递归)
 */
int f(int n) {
    if (n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    }
    return f(n-1) + f(n-2);
}

// 菲波那契迭代法
int fib(int n) {
    if (n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    }
    
    int *notes = (int*)malloc(sizeof(int)*(n+1));
    notes[0] = 0;
    notes[1] = 1;
    int i;
    for (i=2;i<=n;i++) {
        notes[i] = notes[i-1] + notes[i-2];
    }
    return notes[n];
}

// 菲波那契优化, 每项计算只取决于它前面的两项
int fib_solver(int n) {
    int a = 0;  // n-2项
    int b = 1;  // n-1项
    if (n==0) {
        return a;
    }
    if (n==1) {
        return b;
    }
    int i;
    for (i=2;i<=n;i++) {
        int tmp = a + b;    // 前面两项结果赋值tmp
        a = b;              // 向后迭代
        b = tmp;            // b = a+b
    }
    return b;
}

/**
 * 牛顿迭代法,求平方根
 */
const double eps = 0.00000001;  // 1e-5
double sqrt(double x) {
    float val = x;
    float last;
    do {
        last = val;
        val = (val + x / val) / 2;
    }while(fabsf(val - last) > eps);
    
    return val;
}

/**
 * 方程ax3+bx2+cx+d=0,输出x在1附近的一个实根
 * 牛顿迭代法解方程
 */
int a,b,c,d;
double func(double x) {
    double y;
    y = ((a*x+b)*x+c)*x+d;
    return (y);
}

/**
 * 方程的导数方法
 */
double dfunc(double x) {
    double y;
    y = (3*a*x+2*b)*x+c;
    return (y);
}
/**
*方程为ax^3+bx^2+cx+d=0
* 系数a, b, c, d的值依次为1, 2, 3, 4，由主函数输入。求x在1附近的一个实根。求出根后由主函数输出。
牛顿迭代法的公式是x = x0 - f(x0) / f '(x)，精度为10^-5。
**/
double main_newdon(double x) {
    double x0 = 1.0, x1; // x0是初始值
    x1 = 1;
    do {
        x1 = x0 - func(x0)/dfunc(x0);
    } while (fabs(x1-x0) >= eps);
    
    return x1;
}

/**
 void new_don() {
     float x , f1 ,f2 , d;
     x = 1;//初值
     do {
         f1 = fun1( x); //f(x0)的值
         f2 = fun2( x); //f‘（x0）的值
         d = f1 / f2;   //x的偏移值
         x -= d;        //下一个x值
     }
     while(fabs(d) > 1e-5); //判断精度，不满足则继续循环，满足的跳出，fabs是取绝对值
     printf("%.5f\n\n",x);
 }
 */


/**
 * 二分法
 */
double sqrt_1(double x) {
    float start = 0;
    float last = x;
    while(start < last) {
        float mid = (start + last) / 2;
        if(fabs(mid * mid - x) < eps) return mid;
        else if(mid * mid < x) start = mid;
        else if(mid * mid > x) last = mid;
    }
    return -1;
}

/**
* 找出数组中连续元素乘积最大的值
*/
int maxSerialProduct(int a[], int n) {
    int max = -1;
    int dpmax = a[0];
    int dpmin = a[0];
    
    int i;
    for (i=0;i<n;i++) {
        if (a[i] < 0) {
            int temp = dpmax;
            dpmax = dpmin;
            dpmin = temp;
        }
        dpmax = dpmax*a[i]>a[i]?dpmax*a[i]:a[i];
        dpmin = dpmin*a[i]<a[i]?dpmin*a[i]:a[i];
        max = max>dpmax?max:dpmax;
    }
    printf("max producct: %d\n",max);
    return max;
}
    
