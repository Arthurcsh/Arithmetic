//
//  LinkerTable.c
//  FISample
//
//  Created by CSH on 2020/4/19.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#include "LinkerTable.h"
#include <stdlib.h>
#include <stdbool.h>


Node* createHeadNode() {
    Node *headNode = (Node*)malloc(sizeof(Node));
    headNode->next = NULL;
    
    return headNode;
}

/**
 * 不要一次性开辟一块连续的存储空间, 每次少开辟一点
 * 最后利用指针将所有开辟的小的存储空间链接在一起, 组成一个整体
 *
 * 动态链表头插法
 * 规则:
 1.把新结点的下一个结点指向头结点的下一个结点
 2.把头结点的下一个结点指向新结点
 */
Node* initLinker() {
    // 创建一个头指针和头结点(链表带有头节点)
    Node *headNode = (Node*)malloc(sizeof(Node));
    headNode->next = NULL;
    
    // 生成链表
    int i;
    for (i=1; i<MAXSIZE; i++) {
        Node *node = (Node*)malloc(sizeof(Node));
        
        // 创建节点数据域
        node->data = i;
        // 1. 把新节点的下一个节点指向头节点的下一个节点
        node->next = headNode->next;
        // 2. 把头节点的下一个节点指向新节点
        headNode->next = node;
    }
    
    return headNode;
}

// 在链表的头部插入节点
Node* insertHeadNode(Node* head, int element) {
    if (head == NULL) return head;
    
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;
    node->next = head->next;
    head->next = node;
    
    return head;
}

/**
 * 动态链表的尾插法
 * 规则:
 1. 定义变量记录最后一个结点
 2. 让新结点成为上一个结点的下一个结点
 3. 把新结点作为下一个结点的上一个结点
 */
Node* createLinker() {
    // 1. 创建头节点和头指针
    Node *head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        exit(-1);
    }
    head->next = NULL;
    
    // 2. curNode当前节点
    Node *curNode = NULL;
    // 2. 定义节点变量记录最后一个节点
    Node *tail = head;
    // 生成链表
    int i;
    for (i=1; i<MAXSIZE; i++) {
        curNode = (Node*)malloc(sizeof(Node));
        curNode->data = i;
        curNode->next = NULL;
        
        tail->next = curNode;  // tail尾节点next指向新的尾节点
        tail = curNode;        // tail记录尾节点
    }
    return head;
}

/**
 * 查找链表中指定值的节点
 */
Node* findLinkerNode(Node *head, NElemType key) {
    // 主要：头节点不需要查找
    head = head->next;
    while (head != NULL) {
        // 判断当前节点保存的值是否是要查找的值
        if (head->data == key) {
            return head;
        } else {
            head = head->next;
        }
    }
    return NULL;
}

/**
 * 链表反转，头插法
 */
Node reverserNode(Node *head) {
    Node *reverse = NULL;
    // 定义遍历指针，初始化为头节点
    Node *point = head;
    
    // 遍历链表
    while (point != NULL) {
        // 记录下一个节点
        Node *temp = point->next;
        // 当前节点next指向新链表头
        point->next = reverse;
        // 更改新链表头为当前节点
        reverse = point;
        // 移动指针继续先期记录的下个节点
        point = temp;
    }
    return *reverse;
}

/**
 * 链表反转，递归法
 */
Node* curservieReverserNode(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // 遍历到链表尾部
    Node *reverser = curservieReverserNode(head->next);
    // 反转
    head->next->next = head;
    head->next = NULL;
    
    return reverser;
}

/**
 * 非递归
 */
Node* reverseNode(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *pre = head->next;
    Node *cur = pre->next;
    pre->next = NULL;   // 链表尾置空
    if (cur == NULL) {
        return head;
    }
    
    while (cur != NULL) {
        Node *pnext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pnext;
    }
    head->next = pre;
    return head;
}

/**
 * 链表反转,迭代单链表
 */
Node* iterationLinker(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *newHead = NULL;
    while (head) {
        Node *tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
        printf(" %d", head->data);
    }
    
    return newHead;
}

// 打印链表
void printLinkerNode(Node *head) {
    Node *next = head->next;
    while (next != NULL) {
        printf(" %d", next->data);
        next = next->next;
    }
    printf("\n");
}

// 链表相邻节点两两交换(递归)
Node* swapPairsRecursive(Node *head) {
    if (!head || !head->next) {
        return head;
    }
    
    Node *prev = head;
    Node *curn = head->next;
    Node *last = curn->next;
    last = swapPairsRecursive(last);
    curn->next = prev;
    prev->next = last;
    
    return curn;
}

// 链表相邻节点两两交换
Node* swapPairs(Node *head) {
    if (head == NULL || head->next) return head;
    
    Node *prev = head;
    while (prev->next && prev->next->next) {
        Node *tmp = prev->next->next;
        prev->next->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
        prev = tmp->next;
    }
    return prev;
}


void swapParsLinker() {
    Node *head = initLinker();
    
    printf("swapParsLinker: \n");
    swapPairs(head);
    printLinkerNode(head);
    
    printf("\n");
}

// KMP
void cal_next(char *str, int *next, int len) {
    int q;
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;  //k初始化为-1
    for (q = 1; q <= len-1; q++) {
        //如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        while (k > -1 && str[k + 1] != str[q]) {
            k = next[k];//往前回溯
        }
        if (str[k + 1] == str[q])//如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}

// 创建链表单节点
Node* createNumNode(NElemType element) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;
    
    return node;
}

// 用单向链表表示十进制整数，求两个正整数之和
Node* addNumberWithLinker(Node *node1, Node *node2) {
    Node *resNode1 = curservieReverserNode(node1);
    Node *resNode2 = curservieReverserNode(node2);
    
    int carry = 0; //进位数
    Node *head = createNumNode(0);
    while (resNode1 || resNode2 || carry!=0) {
        int sum = 0;
        if (resNode1!=NULL) sum+=resNode1->data;
        if (resNode2!=NULL) sum+=resNode2->data;
        
        carry = sum/10; //进位等于总数除以十
        sum += carry;
        
        Node *newNode = createNumNode(sum%10);
        // 新节点尾插法
        newNode->next = head->next;
        head->next = newNode;
        if (resNode1) resNode1 = resNode1->next;
        if (resNode2) resNode2 = resNode2->next;
    }
    
    return head;
}

// 检测两链表十进制相加
void addNumberNode() {
    // 创建一个头指针和头结点
    Node *headNode1 = (Node*)malloc(sizeof(Node));
    headNode1->next = NULL;
    insertHeadNode(headNode1,9);
    insertHeadNode(headNode1,5);
    insertHeadNode(headNode1,2);
    insertHeadNode(headNode1,7);
    insertHeadNode(headNode1,1);
    
    Node *headNode2 = (Node*)malloc(sizeof(Node));
    headNode2->next = NULL;
    insertHeadNode(headNode2,4);
    insertHeadNode(headNode2,6);
    
    Node *reverse = addNumberWithLinker(headNode1, headNode2);
    printLinkerNode(reverse);
    printf("\n");
}

/**
 * 判断一个链表是否是回文结构
 */
bool isPalindrome(Node *head) {
    if (!head || !head->next) return true;
    
    int length = 0;
    Node *next = head->next;
    Node *slow = next;
    Node *fast = next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;   // 遍历到mid处
        fast = fast->next->next;
        length++;
    }
    
    Node *stack[length];
    int stackTop = -1;
    // 继续从慢指针mid位置遍历
    while (slow != NULL) {
        stack[++stackTop] = slow;  // 入栈
        slow = slow->next;
    }
           
    while (stackTop != -1) {
        if (next->data != stack[stackTop--]->data) {
            return false;
        }
        next = next->next;
    }
    
    return true;
}

void stack_palindrome_main() {
    Node *headNode = createHeadNode();
    insertHeadNode(headNode,1);
    insertHeadNode(headNode,2);
    insertHeadNode(headNode,3);
    insertHeadNode(headNode,2);
    insertHeadNode(headNode,1);
    
    printLinkerNode(headNode);
    bool palindrome = isPalindrome(headNode);
    printf("是否链表回文结构: %s\n", palindrome?"YES":"NO");
}


/**
 * 输入一个链表，输出该链表中倒数第K个节点。只用一次遍历时间复杂度O(n)
 * 1、首先让快慢指针同时指向head后继节点；
    2、快指针往前走K-1步，使快慢指针相隔K个节点，会先走到K节点；
    3、快慢指针同时往前走一步，不断重复此步骤，知道快指针走到尾节点，此时的slow节点即是要找的倒序第K个节点
 */

Node* findReverseTailNode(Node *head, int k) {
    if (head == NULL) return head;
    
    Node *slow = head->next;
    Node *fast = head->next;
    
    int index = k - 1;
    while (fast != NULL && index > 0) {
        fast = fast->next;
        index--;
    }
    
    // fast指针领先slow指针k个节点，当fast到达链表结尾时，此时slow节点即是该链表倒数第k个节点
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

/**
 * 有序单链表的合并，生成一个有序的单链表，递归做法
 */
Node* merger_linker_recursive(Node *node1, Node *node2) {
    Node *newNode;
    if (node1 == NULL) {
        return node2;
    } else if (node2 == NULL) {
        return node1;
    } else {
        if (node1->data < node2->data) {
            newNode = node1;
            newNode->next = merger_linker_recursive(node1->next, node2);
        } else {
            newNode = node2;
            newNode->next = merger_linker_recursive(node1, node2->next);
        }
    }
    return newNode;
}

Node* merger_linker_interator(Node *node1, Node *node2) {
    if (node1 == NULL) {
        return node2;
    } else if (node2 == NULL) {
        return node1;
    }
    Node *link1, *link2, *merger;
    merger = (Node*)malloc(sizeof(Node));
    link1 = node1->next;  // 由于Node有头节点，从node->next开始
    link2 = node2->next;
    Node *head = merger;
    
    while (link1 != NULL && link2 != NULL) {
        if (link1->data < link2->data) {
            head->next = link1;
            link1 = link1->next;    // 继续遍历
        } else {
            head->next = link2;
            link2 = link2->next;
        }
        //新链表的指针也要向后移动一位
        head = head->next;
    }
    
    //最后一步：当某个链表为空时，将另一个不为空的链表加入到新链表中
    if (link1 == NULL) {
        head->next = link2;
    } else {
        head->next = link1;
    }
    
    return merger;
}

void main_merger_linker() {
    Node *node1 = createHeadNode();
    insertHeadNode(node1,8);
    insertHeadNode(node1,4);
    insertHeadNode(node1,1);
    
    Node *node2 = createHeadNode();
    insertHeadNode(node2,10);
    insertHeadNode(node2,7);
    insertHeadNode(node2,6);
    insertHeadNode(node2,3);
    insertHeadNode(node2,2);
    
//    printLinkerNode(node1);
    Node *merger = merger_linker_interator(node1,node2);
    printLinkerNode(merger);
}
