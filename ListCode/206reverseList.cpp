
/**
 * @file 206reverseList.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "utils.hpp"

/**
 * 
206.反转链表
力扣题目链接(opens new window)

题意：反转一个单链表。

示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL
 * 
*/

class Solution{
public:
    ListNode *reverseList(ListNode *head){

        ListNode *pre {nullptr};
        ListNode *temp {nullptr};
        ListNode *cur {head};
        while(cur != nullptr){
            temp = cur->next; // 缓存 cur->next 
            cur->next = pre; // 反转
            pre = cur;       // pre 后移动
            cur = temp;      // cur 后移
        }
        return pre;
    }
};



int main(){
    std::vector<int> nums = {1,2,3,4,5};
    ListNode *head = vectorToLisCode(nums);
    printListNode(head);
    Solution solution;
    ListNode *result = solution.reverseList(head);
    printListNode(result);

    return 0;
}