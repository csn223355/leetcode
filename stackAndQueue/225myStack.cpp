
/**
 * @file 225myStack.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

class myStack{
public:
    std::queue<int> que;
    myStack() = default;
public:
    bool empty(){
        return que.empty();
    }

    void push(int x){
        que.push(x);
    }

    int top(){
        return que.back();       // 栈顶的元素 相当于队底的元素
    }

    int pop(){                         // 将队列前n的元素全部添加到队尾
        int size = que.size();
        while(size > 1){
            que.push(que.front());
            que.pop();
            --size;
        }
        int ret = que.front();
        que.pop();
        return ret;
    }

};


