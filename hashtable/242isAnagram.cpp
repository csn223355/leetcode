
/**
 * @file 242isAnagram.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
 * 示例 2: 输入: s = "rat", t = "car" 输出: false
 * 说明: 你可以假设字符串只包含小写字母。
 * 
*/


#include <iostream>
#include <vector>
#include <string>

class Solution{
public:
    bool isAngram(std::string s ,std::string t){
        int record[26] = {0};

        for(size_t i{0}; i < s.size(); ++i){
            record[s[i] - 'a']++;
        }

        for(size_t i{0}; i < t.size(); ++i){
            record[t[i] - 'a']--;
        }

        for(size_t i{0}; i < 26; ++i ){
            if(record[i] != 0){
                return false;
            }
        }
        return true;
    }
};




// test
int main(){

    // std::string s = "anagram", t = "nagaram";
    std::string s = "rat", t = "car";
    Solution s1;
    bool ret = s1.isAngram(s,t);
    std::cout << "ret:" << ret << std::endl;



    return 0;
}