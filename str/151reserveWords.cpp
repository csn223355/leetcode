
/**
 * @file 151reserveWords.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 151.翻转字符串里的单词
力扣题目链接(opens new window)

给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

 * 
*/

#include <iostream>
#include <vector>
#include <string>


class Solution{
public:
    void removeExtraSpace(std::string &s){           // 删除字符串里面多余的空格
        int slow {0};
        for(int fast {0}; fast < s.size(); ++fast){
            // 遇到非空格就处理，即删除所有空格
            if(s[fast] != ' '){
                if(slow != 0){  // 不是第一个单词后面需要添加一个空格, 手动给单词之间添加空格，slow != 0说明不是第一个单词，需要在单词前添加空格。
                    s[slow++] = ' ';
                }
                // 
                while(fast < s.size() && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }
    void reverse(std::string &s, int start, int end){
        for(int i{start}, j{end}; i < j; ++i, --j){
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
        }
    }
    std::string reverseWords(std::string s){
        // 删除多余的空格
        removeExtraSpace(s);
        // 对整个字符串作反转
        reverse(s, 0, s.size() - 1 );
        // 对每个单词开始反转
        int start{0};  // removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for(int i{0}; i < s.size(); ++i){
            if(i == s.size() || s[i] == ' '){
                reverse(s, start, i - 1);
                start = i;
            }
        }
        return s;
    }
    
};





// test
int main(){
    return 0;
}