//
//  LinkerPractice.c
//  FISample
//
//  Created by chengshaohua on 2020/5/30.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "LinkerPractice.h"
#include "LinkerTable.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * 练习： 递归单链表反转
 */
Node* reverse_recursive(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    
    Node *newHead = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}
/**
 * 练习： 迭代单链表反转
 */
Node* reverse_node(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *newHead = NULL;
    while (head != NULL) {
        Node *tmp = head->next;  // ①先将链表头节点的下一项记录下来
        head->next = newHead;    // ②取出当前节点head->next，插到newHead的头顶
        newHead = head;          // ③新节点取代原head，直到newHead遍历到链表尾节点
        head = tmp;              // head指向下一个反转的节点，继续迭代
    }
    return newHead;   // 返回已经遍历到尾节点的新头节点
}
void linker_reverse_main() {
    Node *head = initLinker();
    
    printf("reverseLinker: \n");
    Node *newHead = reverse_recursive(head->next);
    printLinkerNode(newHead);   // 由于带有头节点， 头节点没有打印出来
    
    printf("\n");
}

/**
 * 练习：单链表相邻节点逆序
 */
Node* linker_swap_pair(Node *head) {
    if (head == NULL || head->next == NULL) return head;
    
    Node *prev = head;
    while (prev->next != NULL && prev->next->next != NULL) {
        Node *tmp = prev->next->next;
        prev->next->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
        prev = tmp->next;
    }
    return head;
}
// 递归方法
Node* linker_swap_cursive(Node *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
    
    Node *newHead = linker_swap_cursive(head->next->next);
    head->next->next = newHead->next;
    newHead->next = head->next;
    head->next = newHead;
    
    return head;
}
void linker_swap_main() {
    Node *head = initLinker();
    printf("swapLinker: \n");
    linker_swap_cursive(head);
    printLinkerNode(head);   // 由于带\
    \'有头节点， 头节点没有打印出来
    
    printf("\n");
}

/**
 * 求链表倒数第k个节点后滚动链表
 * [1,2,3,4,5,6]倒数第3个节点4后节点滚动[5,6,1,2,3,4]
 */
Node* linker_tail_roll(Node *head, int k) {
    if (head == NULL || head->next == NULL) return head;
    
    // 双指针移动,curn先走k步，随后同时next直到curn->next为NULL
    Node *prev = head;
    Node *curn = head;
    int index = k - 1;
    while (curn->next != NULL) {
        if (index < 1) {
            prev = prev->next;
        }
        curn = curn->next;
        index--;
    }
    
    curn->next = head->next;
    head->next = prev->next;
    prev->next = NULL;
    
    return head;
}
void linker_roll_main() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    insertHeadNode(head,6);
    insertHeadNode(head,5);
    insertHeadNode(head,4);
    insertHeadNode(head,3);
    insertHeadNode(head,2);
    insertHeadNode(head,1);
    
    printLinkerNode(head);
    linker_tail_roll(head,3);
    printLinkerNode(head);
}
