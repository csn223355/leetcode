
/**
 * @file 344reverseString.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 * 
*/

#include <iostream>
#include <vector>
#include <string>

class Solution{
public:
    void reverseString(std::vector<char> &str){
        for(int i{0},j{str.size() - 1}; i < str.size()/2; i++, j--){
            // 1. 通过亦或运算交换
            str[i] ^= str[j];
            str[j] ^= str[i];
            str[i] ^= str[j];
            // 2. 通过临时变量交换
            // char temp = str[i];
            // str[i] = str[j];
            // str[j] = temp;
            // 3. 通过std::swap() 交换
            // std::swap(str[i],str[j]);

        }
    }
};



// test
int main(){
    return 0;
}