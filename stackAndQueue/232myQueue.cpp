/**
 * @file 232myQueue.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>


/**
 * 使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。

示例:

MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
说明:

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
*/

/**
 * 思路 用两个栈模拟队列，一个进栈一个出栈
*/


class myQueque{

public:
    std::stack<int> inStack;
    std::stack<int> outStack;

public:
    myQueque(){}

    bool empty(){
        return inStack.empty() && outStack.empty();
    }
    // 将x插入队列
    void push(int x){
        inStack.push(x);
    }
    // 弹出队列头部的元素
    int pop(){
        if(outStack.empty()){       // 如果出栈为空则 将所有 进栈 元素弹出，然后送到 出栈 里面
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int ret = outStack.top();      //  弹出 出栈 栈首元素
        outStack.pop();
        return ret;
    }
    // 返回队列头部的元素
    int peek(){
        int ret = this->pop();
        outStack.push(ret);
        return ret;
    }
};

