//
//  main.c
//  FISample
//
//  Created by chengshaohua on 2017/11/30.
//  Copyright © 2017年 www.bundwealth.com. All rights reserved.
//

#include <stdio.h>
#include "FIBiTree.h"
#include "FILinker.h"
#include "FISort.h"
#include "BinaryTree.h"
#include "Practice.h"
#include "DoubleLinker.h"
#include "STDLib.h"
#include "DP.h"
#include "LinkerPractice.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    BiTree T;
//    T = CreateBiTree();
//    printf("先序遍历：\n");
//    PreOrderTraverse(T);
//    printf("\n");
    
//    InOrderTraverse(T);
//    printf("\n");
//    PostOrderTraverse(T);
    
    
//    Q1LinkNode *h1 = createQ1LinkNode(78);
//    Q1LinkNode *h2 = addQ1Node(&h1, 8);
//    h2 = addQ1Node(&h1, 1);
//    printQ1Node(h1);
//    printQ1Node(h2);
    
//    swapParsLinker();
//    addNumberNode();
//    linker_reverse_main();
//    linker_swap_main();
//    linker_roll_main();  // 第k个节点后滚动链表
    main_merger_linker();
    
    int array[14] = {31,23,33,52,12,43,63,69,87,26,51,40,24,47};
    main_bubble_sort(array,ARRAY_SIZE(array));
//    selectSort(array,ARRAY_SIZE(array));
    
//    selectedSort(array,ARRAY_SIZE(array));
//    insertSort(array,ARRAY_SIZE(array));
//    insertBinarySort(array,ARRAY_SIZE(array));
    
//    main_merge_sort(array,ARRAY_SIZE(array));
//    quickSorts(array,ARRAY_SIZE(array));
    
//    int  num = 11111;
//    binary_stack(num);
//    binary_array(num);
    
//    char *s = "sdf$$$sdf$$";
//    removePairDuplicate2(s);
    
//    midOrderTreeNode();   // 中序遍历二叉树，递归和非递归
//    postOrderTreeNode();  // 后序遍历二叉树
    
//    sortNumbers();
    
    
//    stringSourceCopy();
//    stringLength();
    
    int arrays[] = {1,8,5,9,5,4,3,1,6,7};
//    int length = searchNonSortsLength(arrays, ARRAY_SIZE(arrays));
//    printf("min length: %d\n",length);
//    findRepetition(arrays, 10);
//    findDuplicate(arrays, 10);
    int list[] = {1,3,5,9,9,12,13,13,16,17};
//    lengthRemoveDupllcates(list, 10);   // 有序数组去重后的长度
    
//    main_merge_list_array();  // 合并两个排序的数组
    
//    stack_reverse(arrays,ARRAY_SIZE(arrays));
    
//    stack_reverse_main();  // 栈逆序
//    queue_stack_main();    // 双栈队列
//    stack_sort_main();     // 辅助栈排序(未通过)
//    stack_palindrome_main();
    
//    stack_queue_main();  // 双栈队列
//    int height[] = {2,1,5,6,2,3};
//    maxRectangleArea(height,6);
    
//    char chars[] = "abdce5323";
//    string_index(chars,ARRAY_SIZE(array),5);
    
//    stringCspan();
//    stringCompare();
//    stringQuery();
//    stringContact();
//    stringIsupper();
//    stringIsspace();
//    stringIsprint();
    
//    string_atoi("-2334sdf34242");
//    char s[20];
//    string_itoa(-688, s);
    
//    int subs[5] = {2,-3,1,5,-1};
//    MaxSubSum(subs,ARRAY_SIZE(subs));
//    robber(subs, 5);
//    maxSerialProduct(subs,ARRAY_SIZE(subs));  // 数组子序列最大元素乘积
    
//    hash_map_main();
//    find_once_char("fewrsdfewr");
    
//    main_heap();
    
    return 0;
}
