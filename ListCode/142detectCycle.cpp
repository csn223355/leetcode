
/**
 * @file 142detectCycle.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/**
 * 题意： 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
*/
#include <iostream>
#include <vector>
#include <string>
#include "utils.hpp"

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        // 1. 确认链表是否存在环
        ListNode *fast {head};
        ListNode *low {head};
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            low = low->next;
            if(fast == low){ // 如果存在环
                ListNode *index1 {fast};
                ListNode *index2 {head};
                while(index1 != index2){ // 计算进入环的节点位置
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }

};


// test
int main(){
    return 0;
}