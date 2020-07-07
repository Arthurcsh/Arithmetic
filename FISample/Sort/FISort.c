//
//  FISort.c
//  FISample
//
//  Created by chengshaohua on 2018/1/28.
//  Copyright © 2018年 www.bundwealth.com. All rights reserved.
//

#include "FISort.h"
#include <string.h>
#include <stdlib.h>

// 遍历打印
void printSorts(int a[],int n) {
    int k = 0;
    printf("--- 数组排序:");
    for(k=0;k<n;k++) {
        printf("  %d",a[k]);
    }
    printf("\n");
}

// 交换值
/**
 *  a = a^b
 *  b = a^b
 *  a = a^b
 *
 *  a ^= b ^= a ^= b;
 *  
 *  位运算符：
 *  & 按位与双目运算符，对应的两个二进制位均为1时，结果位为1
 *  | 按位或双目运算符，对应的两个二进制位有一个为1，结果位为1
 *  ^ 按位异或运算符，对应的两个二进制位相异时，结果位为1，否则为0
 *  ~ 求反单目运算符，对参与运算的数的各二进位按位求反
 *  << 左移运算符，左移n位就是乘以2的n次方。 其功能把“<<”左边的运算数的各二进位全部左移若干位，由“<<”右边的数指定移动的位数，高位丢弃，低位补0
 *  >> 右移运算符，移n位就是除以2的n次方，其功能是把“>>”左边的运算数的各二进位全部右移若干位，
 *     “>>”右边的数指定移动的位数
 */
void exchangeValue(int a[], int m, int n) {
    a[m] = a[m]+a[n]-(a[n]=a[m]);
}

// 冒泡排序
void bubbleSort(int a[],int n) {
    int i=0,j=0,flag=0,pos=0;  // 记录最后一次交换的位置
    int k=n-1;
    for(i=0;i<n-1;i++) {
        flag = 0;
        for(j=0;j<k;j++) {
            if(a[j]>a[j+1]) {
                exchangeValue(a,j,j+1);
                flag = 1;
                pos = j;  // 交换元素，记录最后一次交换的位置
            }
        }
        if (flag==0) {
            return; // 如果没有交换元素， 则已经有序
        }
        k = pos;
    }
}
void main_bubble_sort(int a[], int n) {
    bubbleSort(a, n);
    
    printSorts(a, n);
}


// 选择排序
void selectSort(int a[], int n) {
    int i;
    for(i=0;i<n;i++) {
        int key = selectMinKey(a,i,n);
        if(key != i) {
            exchangeValue(a,i,key);
        }
    }
    
    printSorts(a, n);
}


int selectMinKey(int a[], int i, int n) {
    int k = i;
    int j;
    // 寻找最小元素的下标
    for(j=i+1;j<n;j++) {
        if(a[k] > a[j]) {
            k = j;
        }
    }
    return k;
}

// 选择排序
void selectedSort(int a[], int n) {
    int i, j, min;
    for (i=0;i<n-1;i++) {
        min = i;
        // 寻找最小元素的下标
        for (j=i+1;j<n;j++) {
            if (a[min]>a[j]) {
                min = j;
            }
        }
        // 如果下标有变化，交换两个元素
        if (min!=i) {
            a[i] = a[i]+a[min]-(a[min]=a[i]);
        }
    }
    
    printSorts(a, n);
}

// 插入排序
void insertSort(int a[], int n) {
    int i, j, tmp;
    for (i=1;i<n;i++) {
        tmp = a[i];  // 保存将要移动的元素
        j = i;  // 记录第一个元素下标, 开始向前已排好序的遍历
        while (j>0 && a[j-1]>tmp) {
            a[j] = a[j-1];
            j--;
        }
        // 此时 j 已经移动到a[i]的前位置
        a[j] = tmp;
    }
    
    printSorts(a, n);
}

// 二分插入排序
void insertBinarySort(int a[], int n) {
    int i, j, low, high, m = 0, tmp;
    for (i=1; i<n; i++) {
        low = 0;
        high = i-1;
        while (low<high) {
            m = (low+high)>>1;
            if (a[m] > a[i]) {
                high = m - 1;
            } else {
                low = m + 1;
            }
        }
//        printf("middle: %d   high: %d\n",low,high);
        tmp = a[i];
        for (j=i;j>high+1;j--) {
            a[j] = a[j-1];  // 依次移动需要插入的大于a[i]的元素
        }
        a[high+1] = tmp;
    }
    
    printSorts(a, n);
}

// 合并
void merge(int a[], int low, int mid, int high) {
    int left, right;
    left = mid-low+1;
    right = high-low;
    int l[left], r[right]; //gcc, 两个临时数组，分别保存待合并的两个区间
    //int l[100], r[100];  //vc
    memcpy(l, a + low, sizeof(int) * left);
    memcpy(r, a + mid + 1, sizeof(int) * right);
    
    int i = 0, j = 0, k = low;
    while(i < left && j < right) {
        a[k++] = l[i] < r[j] ? l[i++] : r[j++];
    }

    while(i < left) {
        a[k++] = l[i++];
    }
}
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex) {
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1) {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
/**
 * 动态创建low+high数组，注意及时释放
 */
void merge2(int a[], int low, int mid, int high) {
    int len = high-low+1;
    
    int start1 = low;
    int start2 = mid+1;
    int *temp = (int*) malloc(len * sizeof(int));
    
    int k=low;
    while (start1<=mid && start2<=high) {
        temp[k++] = a[start1]<a[start2]?a[start1++]:a[start2++];
    }
    while (start1 <= mid) {
        temp[k++] = a[start1++];
    }
    while (start2 <= high) {
        temp[k++] = a[start2++];
    }
    memcpy(a+low, temp+low, sizeof(int)*len);
//    k = low;
//    while (k<=high) {
//        a[k] = temp[k];
//        k++;
//    }
    
    free(temp);
}

int* merge3(int left[], int l, int right[], int r) {
//    int[] result = new int[left.length + right.length];
//    for (int index = 0, i = 0, j = 0; index < result.length; index++) {
//        if (i >= left.length)
//            result[index] = right[j++];
//        else if (j >= right.length)
//            result[index] = left[i++];
//        else if (left[i] > right[j])
//            result[index] = right[j++];
//        else
//            result[index] = left[i++];
//    }
//    return result;
    return NULL;
}

/**
 * 归并另一种方法
 */
int *mergeSort3(int a[], int n) {
    if (n < 2) return a;
    
    int mid = n>>1;
    int left[mid];
    int right[n-mid];
    memcpy(a, left, sizeof(int)*mid);
    memcpy(a+mid, right, sizeof(int)*(n-mid));
    return merge3(mergeSort3(left, mid), mid, mergeSort3(right, n-mid), n-mid);
}

// 归并排序
void mergeSort(int a[], int low, int high) {
    // 递归终止条件
    if (low >= high) {
        return;
    }
    
    int mid = (low + high)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge2(a, low, mid, high);
}
void main_merge_sort(int a[], int n) {
    mergeSort(a, 0, n-1);
    
    printSorts(a, n);
}

// 快速排序
void quickSort(int a[], int low, int high) {
    int key = a[low];
    int left = low;
    int right = high;
    
    if (low >= high) {
        // 如果low >= high说明排序结束了
        return;
    }
    
    // while循环一次表示比较一轮
    while (low < high) {
        while (low<high && a[high]>=key) {
            high--;   // 向前寻找
        }
        if (key > a[high]) {
            exchangeValue(a,low,high);
            low++;
        }
        
        while (low<high && a[low]<=key) {
            low++;  // 向后寻找
        }
        if (key < a[low]) {
            exchangeValue(a,low,high);
            high--;
        }
    }
    
    quickSort(a, left, low-1);
    quickSort(a, low+1, right);
}

/**
 * 快速排序法采用递归，每次用数组第一个作为基数mid把当前数组区间分隔成[low-mid-high]两个序列
 * 再分别递归[low-mid]和[mid-high]，直至递归到low=high，每个元素都为基数mid
 */
void quickSort2(int a[], int left, int right) {
    if (left >= right) return;  // 待排序子序列至少有两个元素
    
    int low = left;
    int high = right;
    int key = a[left];
    while (low < high) {
        while (low < high && key <= a[high]) {
            high--;
        }
        /*找到一个这样的数后就把它赋给前面的被拿走的low的值（如果第一次循环且key是
        a[left]，那么就是给key）*/
        a[low] = a[high];
        
        while (low < high && key >= a[low]) {
            low++;
        }
        /*这是low在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        a[high] = a[low];
    }
    
    /*直到left=right当在当组内找完一遍以后就把中间数key回归*/
    a[low] = key;
    quickSort2(a, left, low-1);
    quickSort2(a, low+1, right);
}
void quickSorts(int a[], int n) {
//    quickSort(a, 0, n-1);
    quickSort2(a, 0, n-1);
    
    printSorts(a, n);
}

// 需要排序的最短子数组的长度, 也可以采用双指针法
int searchNonSortsLength(int a[], int n) {
    int i,j,left, right, tmp=a[0];
    
    left = 0;    // 从左向右比较最大值
    right = n-1;  // 从右向左比较最小值
    for (i=1;i<n;i++) {
        if (a[i] < tmp) { // 当前值 < max
            left = i;
        } else {
//            tmp = (tmp>a[i]?tmp:a[i]);
            tmp = a[i];
        }
    }
    
    tmp = a[n-1];
    for (j=n-2;j>=0;j--) {
        if (a[j] > tmp) {
            right = j;
        } else {
//            tmp = (tmp<a[j]?tmp:a[j]);
            tmp = a[j];
        }
    }
    return left-right+1;
}

/**
 * 快速排序应用
 * 查找无序数组的中位数
 */
int findMedian(int a[], int n) {
    
    return 0;
}

/**
 * 希尔排序
 * 希尔排序的核心，将一维数组逻辑划分为矩阵形式，依次减少矩阵的列，最后形成只有一列的数组。
 * 在每一次划分逻辑矩阵时，均对每一列进行插入操作，让每一列变得更加有序。
 * 在代码中定义一个跨度--gap，从而生成逻辑上的矩阵。
 * step 一般可以通过列表反复除2得出，直到为0终止(整型除法特点)
 */
void shellSort(int a[], int n) {
    int step;
    for (step=n/2; step>0; step/=2) {
        int i,j,curn;
        // 按列插入排序
        // 插入排序有个特点：已插入排序的数组都是有序的，因此后面的元素可以直接单向往前比较即可找到合适的位置。
        // 从插入排序得出的经验，从第二个元素开始插入，在这里就是第二行。因此 i=gap 开始。
        // 这里的插入方法借鉴于wiki，当然可以使用自己的逻辑进行插入。
        // 上一篇的【插入排序】使用的就是自己最原始直观的逻辑。
        for (i=step; i<n; i++) {
            curn = a[i];
            // 开始插入，其它元素移位。按已排序数组的后端开始移位
            for (j=i-step; j>=0 && (a[j] > curn); j-=step) {
                // 如果当前元素 tmp 小于该位置元素，则该位置元素向后移动
                // wiki 中退出循环逻辑，通过for中的条件控制，这里为了方便思考，顾单独拿出来。
                // 前一个元素后移
                a[j+step] = a[j];
            }
            a[j+step] = curn;
        }
    }
}


/**
 * 长度为n的数组乱序存放着0至n-1. 现在只能进行0与其他数的交换，完成数组排序
 *

 代码思路：
 1、要使数组array[i]为i,又因只能与0交换，所以要先让0在这个位置上，即swapWithZero(array, len, array[i]);
 2、然后将i与0交换：swapWithZero(array, len, i); 即可使数组array[i]==i
 */
extern void swap_with_zero(int* array, int len, int n);

void sort(int array[], int len) {
    // 完成这个函数
    int i;
    for(i=0;i<len;i++){
        //可加个判断：array[i] == i则跳下一个数， 可减少执行次数
//        swapWithZero(array, len, array[i]);//将0换到i的位置
//        swapWithZero(array, len, i);//将i与0交换，i放到array[i]的位置
    }
}

/**
 * 从0～n的数组nums里查找重复的数字，数组的值也在0～n中 (特殊的数据结构)
 */
void findRepetition(int nums[], int n) {
    int list[n];
    int i;
    for (i=0;i<n;i++) {
        list[i] = -1;
    }
    
    for (i=0;i<n;i++) {
        if (list[nums[i]] == -1) {
            list[nums[i]] = nums[i];
        } else {
            printf("重复数字: %d ", nums[i]);
        }
    }
    printf("\n");
}

// 参考环形链表II，利用快慢指针
// 快指针一次走两步，慢指针一次走一步，当他们相遇后
// 快指针再次从起点出发，但此时两个指针都是一次走一步
// 当他们再次相遇后，相遇点就是重复的整数
// 假设数组是[1, 5, 7, 3, 2, 4, 6, 7]，
// 那么将其转化成的链表就是：`0 -> 1 -> 5 -> 7 -> 3 -> 2 -> 4 -> 6 -> 7 ....`无限循环
void findDuplicate(int nums[], int n) {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    
    fast = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    printf("重复数字: %d\n", fast);
}

/**
 * 给定任意一个有序数组，计算出去重后的数组长度,
 * 要求：只能在原数组中进行更改
 * 快慢指针法
 */
int lengthRemoveDupllcates(int nums[], int n) {
    int slow = 0; int fast;
    
    for (fast=0;fast<n;fast++) {
        if (nums[slow] != nums[fast]) {
            nums[++slow] = nums[fast];
        }
    }
    printf("去重后数字长度: %d\n", slow+1);
    return slow+1;
}
