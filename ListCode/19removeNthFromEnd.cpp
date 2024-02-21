
/**
 * @file 19removeNthFromEnd.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "utils.hpp"


/**
 * 19.删除链表的倒数第N个节点


给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

示例 1：

19.删除链表的倒数第N个节点

输入：head = [1,2,3,4,5], n = 2 输出：[1,2,3,5] 示例 2：

输入：head = [1], n = 1 输出：[] 示例 3：

输入：head = [1,2], n = 1 输出：[1]
 * 
*/



class Solution{
public:
    ListNode *removeNthFormEnd(ListNode *head, int n){
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *fast = dummy_head;
        ListNode *slow = dummy_head;
        while(n-- && fast){
            fast = fast->next;
        }
        fast = fast->next;   // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        // 删除slow后面的节点
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        // slow->next = temp->next;
        delete temp;
        return dummy_head->next;
    }
};




// test
int main(){

    return 0;
}

