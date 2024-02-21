/**
383. 赎金信

给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

注意：

你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

/**
 * @file 383canConstruct.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>

class Solution{
public:
    bool canConstruct(std::string &s1,std::string &s2){
        int record [26] {0};
        for(char s: s2){
            record[s - 'a']++;
        }
        for(char s : s1){
            record[s - 'a']--;
        }
        for(int i{0}; i < 26; ++i){
            if(record[i] < 0){
                return false;
            }
        }
        return true;
    }
    bool canConstruct1(std::string &s1,std::string &s2){
        int record [26] {0};
        if(s1.length() > s2.length()){
            return false;
        }
        for(int i{0}; i < s2.length(); ++i){
            record[s2[i] - 'a']++;
        }
        for(int j{0}; j < s1.length(); ++j){
            record[s1[j] - 'a']--;
            if(record[s1[j] - 'a'] < 0){
                return false;
            }
        }
        return true;

    }
    
};

// test
int main(){
    std::string s1 {"aabc"},s2{"aacbsdffsad"};
    Solution solution;
    bool ret = solution.canConstruct1(s1,s2);
    std::cout << "ret:" << ret << std::endl;
    return 0;
}