
/**
 * @file 28strStr.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-02-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 28. 实现 strStr()
力扣题目链接(opens new window)

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2

示例 2: 输入: haystack = "aaaaa", needle = "bba" 输出: -1

说明: 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution{
public:
    void getNext(int *next, const std::string &s){
        /**
         * 1. 初始next数组
         * 2. 前后缀不相同的情况下，
         * 3. 前后缀相同的情况下
         * 4. 更新next数组
        */
        // i:后缀，j:前缀/i之前的 最大相等前后缀长度
        // 初始化next数组
        int j {0};
        next[0] = 0;
        for(int i{1}; i < s.size(); ++i){
            // 前后缀不相同的情况下
            while(j > 0 && s[j] != s[i]){
                j = next[j-1];
            }
            // 前后缀相同的情况下
            if(s[j] == s[i]){
                j++;
            }
            // 更新next数组
            next[i] = j;
        }
    }
    int strStr(const std::string &haystack, const std::string &needle){

        if(needle.size() == 0){
            return 0;
        }
        int next [needle.size()];
        getNext(next, needle);
        int j {0}; // j next 索引
        for(int i{0}; i < haystack.size(); ++i){
            // 匹配不上
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            // 匹配成功
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i - needle.size() + 1);
            }
        }
        return -1;

    }
        

};
// test
int main(){

    std::string haystack = "aabaabaaf";
    std::string needle = "aabaaf";
    Solution solution;
    int next [needle.size()];
    solution.getNext(next, needle);
    std::cout << "next:";
    for(int i{0}; i < needle.size(); ++i){
        std::cout << next[i] << ", ";
    }
    std::cout << std::endl;
    
    int ret = solution.strStr(haystack, needle);
    std::cout << ret << std::endl;
    return 0;
}