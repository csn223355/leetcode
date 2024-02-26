#pragma once
/**
 * @file utils.hpp
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

using namespace std;


struct ListNode{
    int val{0};
    ListNode *next{nullptr};
    ListNode():val(0),next(nullptr){}
    ListNode(int val): val(val),next(nullptr){}
    ListNode(const ListNode &src):val(src.val),next(nullptr){
        if(src.next != nullptr){
            next = new ListNode(*(src.next));
        }
    }
    ~ListNode() {
        // 在析构函数中释放动态分配的内存
        if (next != nullptr) {
            delete next;
        }
    }
    ListNode &operator=(const ListNode &rhs) {
        if (this != &rhs) {
            val = rhs.val;

            // 先释放原有的内存
            delete next;

            // 深度复制链表
            if (rhs.next != nullptr) {
                next = new ListNode(*(rhs.next));
            } else {
                next = nullptr;
            }
        }
        return *this;
    }
   
};


ListNode* vectorToLisCode(const vector<int> &vec){
    if(vec.empty()){
        return nullptr;
    }
    ListNode *head = new ListNode(vec.at(0));
    ListNode *cur = head;
    for(size_t i{1}; i < vec.size(); ++i){
        cur->next = new ListNode(vec.at(i));
        cur = cur->next;
    }
    return head;
}

void printListNode(ListNode *head){
    std::cout << "begin: ";
    while(head != nullptr){
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

}

struct TreeNode
{   
    int val{0};
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(const TreeNode &src): val(src.val), left(nullptr), right(nullptr){
        if(src.left != nullptr){
            left = new TreeNode(*(src.left));
        }
        if(src.right != nullptr){
            right = new TreeNode(*(src.right));
        }
    }
    ~TreeNode(){
        if(left != nullptr){
            delete left;
        }
        if(right != nullptr){
            delete right;
        }
    }

    TreeNode &operator=(const TreeNode& rhs){
        if(this != &rhs){
            val = rhs.val;
            if( left && rhs.left){
                *left = *rhs.left;
            }else{
                left = rhs.left ? new TreeNode(*rhs.left) : nullptr;
            }
            if(right && rhs.right){
                *right = *rhs.right;
            }else{
                right = rhs.right ? new TreeNode(*rhs.right) : nullptr;
            }
        }
        return *this;
    } 
};



template <typename T>
void printVector(const std::vector<T> &nums){
    for(const T &it : nums){
        std::cout << it << ", ";
    }
    std::cout << std::endl;
}


