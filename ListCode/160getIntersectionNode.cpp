
/**
 * @file 160getIntersectionNode.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 * 
*/

#include <iostream>
#include <vector>
#include <string>
#include "utils.hpp"

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *curA {headA};
        ListNode *curB {headB};
        // 获取A，B链表长度
        int lenA {0}, lenB {0};
        while(curA != nullptr){
            ++lenA;
            curA = curA->next;
        }
        while(curB != nullptr){
            ++lenB;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 长链表为A ， 短链表为B
        if(lenB > lenA){
            std::swap(lenB,lenA);
            std::swap(curB,curA);
        }

        int gap {lenA - lenB};
        // curA 先走 gap 步
        while(gap--){
            curA = curA->next;
        }
        while(curA != nullptr){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }

};

// test
int main(){
    // std::vector<int> numsA = {4,1,8,4,5};
    // std::vector<int> numsB = {5,0,1,8,4,5};
    // ListNode *headA = vectorToLisCode(numsA);
    // ListNode *headB = vectorToLisCode(numsB);
    // Solution solution;
    // auto result = solution.getIntersectionNode(headA,headB);
    // printListNode(result);
    return 0;
}