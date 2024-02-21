
/**
 * @file 203.移除链表元素.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "utils.hpp"

using namespace std;

class Solution{
public:
    ListNode *removeElements(ListNode *head, int val){
        // 创建一个虚拟头节点
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *current = dummy_head;
        while(current->next != nullptr){
            if(current->next->val == val){
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp; 
            }else{
                current = current->next;
            }
        }
        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
    ListNode *removeElements1(ListNode *head, int val){
        // 对头节点进行处理
        while(head != nullptr && head->val == val){
            
            ListNode *temp {head};
            head = head->next;
            delete temp;
            
        }
        // 对非头节点进行处理
        ListNode *cur {head};
        while(cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *temp {cur->next};
                cur->next = cur->next->next;
                delete temp;
            }
            cur = cur->next;
        }
        return head;

    }
};



// test
int main(){
    vector<int> vec {1,1,1,1,1,1,1,1,1,1,2,3,3,3,3,3,3,3,3,5,6,7,8,9};
    ListNode *head = vectorToLisCode(vec);
    printListNode(head);
    Solution solution;
    ListNode *result = solution.removeElements1(head, 1);
    printListNode(result);
    // delete head;
    

  return 0;
}