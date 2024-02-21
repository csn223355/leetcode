
/**
 * @file test_stack.cpp
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
#include <stack>


// test
int main(){

    std::stack<int> stack1;
    for(int i{0}; i < 10; ++i){
        stack1.push(i);
    }
    // 获取栈顶元素
    std::cout << "stack1 Top element: " << stack1.top() << std::endl;
    // 出栈
    stack1.pop();
    // 获取修改后的栈顶元素
    std::cout << "Top element after pop: " << stack1.top() << std::endl;
    if(stack1.empty()){
        std::cout << " stack1 is empty!" << std::endl;
    }else{
        std::cout << " stack1 is not empty!" << std::endl;
    }
    std::cout << " stack1 size is " << stack1.size() << std::endl;
    std::stack<int> stack2 {stack1};
    // 获取栈顶元素
    std::cout << "stack2 Top element: " << stack2.top() << std::endl;

    if(stack2 == stack1){
        std::cout << "stack2 == stack1" << std::endl;
    }else{
        std::cout << "stack2 != stack1" << std::endl;
    }
    std::stack<int> stack3 = stack1;

    stack3.pop();
    stack3.pop();
    // 获取栈顶元素
    std::cout << "stack3 Top element: " << stack3.top() << std::endl;

    if(stack3 == stack1){
        std::cout << "stack3 == stack1" << std::endl;
    }else{
        std::cout << "stack3 != stack1" << std::endl;
    }

    std::stack<int> stack4(stack3);
    stack4.pop();
    stack4.pop();
    // 获取栈顶元素
    std::cout << "stack4 Top element: " << stack4.top() << std::endl;
    if(stack4 == stack1){
        std::cout << "stack4 == stack1" << std::endl;
    }else{
        std::cout << "stack4 != stack1" << std::endl;
    }




    return 0;
}