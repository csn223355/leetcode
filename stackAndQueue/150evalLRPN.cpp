
/**
 * @file 150evalLRPN.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 根据 逆波兰表示法，求表达式的值。

有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：

输入: ["2", "1", "+", "3", " * "]
输出: 9
解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", " * ", "/", " * ", "17", "+", "5", "+"]

输出: 22
 * 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

class Solution{
public:
    int evalLRPN(std::vector<std::string> &tokens){
        std::stack<long long> st;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i] == "-" || tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/"){
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if(tokens[i] == "-") st.push(num1 - num2);
                else if(tokens[i] == "+") st.push(num1 + num2);
                else if(tokens[i] == "*") st.push(num1 * num2);
                else if(tokens[i] == "/") st.push(num1 / num2);
            }else{
                st.push(std::stoll(tokens[i]));
            }
        }
        int ret = st.top();
        st.pop();
        return ret;
    }
};

