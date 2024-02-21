
/**
 * @file test_dequeue.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <deque>

template <typename T>
void printDeque(const std::deque<T> &deque){
    for(const auto &it : deque){
        std::cout << it << " "; 
    }
    std::cout << std::endl;
}

// test
int main(){

    std::deque<int> mydeque;
    for(int i{0}; i < 10; ++i){
        mydeque.push_back(i);
    }
    printDeque(mydeque);

    std::deque<float> mydeque1;
    for(int i{0}; i < 10; ++i){
        mydeque1.push_front(i * 0.1f);
    }
    printDeque(mydeque1);
    std::cout << "mydeque[0]:" << mydeque.at(0) << std::endl;
    std::cout << "mydeque1[0]:" << mydeque1.at(0) << std::endl;

    return 0;
}