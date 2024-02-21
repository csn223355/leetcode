
/**
 * @file 24swapPairs.cpp
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

class Solution{

public:
    ListNode *swapPairs(ListNode *head){
        ListNode *dumy_head {new ListNode(0)};
        dumy_head->next = head;
        ListNode *cur {dumy_head};
        ListNode *temp {nullptr};
        ListNode *temp1 {nullptr};

        while(cur->next != nullptr && cur->next->next != nullptr){
            temp = cur->next;
            temp1 = cur->next->next->next;

            cur->next = cur->next->next;        // 步骤一
            cur->next->next = temp;             // 步骤二
            cur->next->next->next = temp1;       // 步骤三

            cur = cur->next->next;              // 往后移动两个

        }
        return dumy_head->next;

    }
};


// test
int main(){

    std::vector<int> nums = {1,2,3,4,5,6};
    ListNode *head = vectorToLisCode(nums);
    // printListNode(head);
    Solution solution;
    ListNode *result = solution.swapPairs(head);
    // printListNode(result);
    return 0;
}