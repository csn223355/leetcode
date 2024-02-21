
/**
 * @file 707MyLinkList.cpp
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
private:
    ListNode *_dumy_head {nullptr};
    int _size {0};
public:
    Solution(){
        _dumy_head = new ListNode(0);
        _size = 0;
    }
    Solution(ListNode *head){
        _dumy_head = new ListNode(0);
        _dumy_head->next = head;
        ListNode *cur = _dumy_head->next;
        int i{0};
        while(cur != nullptr){
            cur = cur->next;
            i++;
        }
        _size = i;
    }
    // 头部添加节点
    void addAtHead(int val){
        ListNode *new_code {new ListNode(val)};
        new_code->next = _dumy_head->next;
        _dumy_head->next = new_code;
        _size++;
    }
    // 尾部 添加节点
    void addAtTail(int val){
        ListNode *new_code {new ListNode(val)};
        ListNode *cur {_dumy_head};
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = new_code;
        _size ++;
    }
    // 指定索引位置添加节点
    void addAtIndex(int index, int val){
        if(index < 0){
            index = 0;
        }else if(index > _size -1){
            return;
        }
        ListNode *new_code {new ListNode(val)};
        ListNode *cur {_dumy_head};
        while(index --){
            cur = cur->next;
        }
        new_code->next = cur->next;
        cur->next = new_code;
        _size ++;

    }
    // 获取索引的值
    int get(int index){
        if(index < 0 || index > (_size -1)){
            return -1;
        }
        ListNode *cur {_dumy_head};
        while(index --){
            cur = cur->next;
        }
        return cur->next->val;

    }
    // 删除指定索引
    void deleteAtIndex(int index){
        if(index < 0 || index > (_size -1)){
            return;
        }
        ListNode *cur {_dumy_head};
        while(index --){
            cur = cur->next;
        }
        ListNode *temp {cur->next};
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        _size --;
    }
    // 打印链表
    void printListNode(){
        std::cout << "ListNode:";
        ListNode *cur = _dumy_head->next;
        while(cur != nullptr){
            std::cout << cur->val << ", ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};




int main(){

    std::vector<int> nums = {1,2,3,4,5,6,3};
    ListNode *head = vectorToLisCode(nums);
    printListNode(head);
    Solution solution(head);
    solution.addAtHead(0);
    solution.printListNode();
    solution.deleteAtIndex(1);
    solution.printListNode();
    solution.addAtIndex(2, 4);
    solution.printListNode();
    auto ret = solution.get(4);
    std::cout << "ret = " << ret << std::endl;
    solution.addAtTail(10);
    solution.printListNode();



    return 0;
}




// test
