
/**
 * @file replaceNumber.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>



// test
int main(){
    std::string s;
    while(std::cin >> s){
        int old_size {s.size()};       // 记录原来字符长度
        int count {0};                  // 记录原来字符串中的数字个数
        for(int i{0}; i < old_size; ++i){
            if(s[i] <= '9' && s[i] >= '0' ){
                ++count;
            }
        }
        
        // s扩容
        s.resize(old_size + count * 5);         // 扩容，有几个数数字就扩容几个size(“number”) - 1
        int new_size {s.size()};                // 获取新的数组size
        for(int i{old_size - 1}, j{new_size - 1}; i < j ; i--, j--){    // 双指针 i 旧数组尾巴。 j 新数组尾巴 
            if(s[i] > '9' || s[i] < '0'){       // 如果是字母则 将旧数组字符复制到新数组对应位置
                s[j] = s[i];
            }else{                              // 如果是数字则
                s[j] = 'r';
                s[j-1] = 'e';
                s[j-2] = 'b';
                s[j-3] = 'm';
                s[j-4] = 'u';
                s[j-5] = 'n';
                j -= 5;
            }
        }
        std::cout << "new_s:" << s << std::endl;
        return 0;
    }

}