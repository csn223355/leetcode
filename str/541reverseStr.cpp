
/**
 * @file 541reverseStr.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 541. 反转字符串II
力扣题目链接(opens new window)

给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。

如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"

#
 * 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class Solution{
public:
    std::string reverseStr(std::string s, int k){
        for(int i{0}; i < s.size(); i += 2 * k){
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if(i + k <= s.size()){    // 如果前k个 则开始反转
                std::reverse(s.begin() + i, s.begin() + i + k);
            }else{ // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                std::reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};


// test
int main(){
    return 0;
}