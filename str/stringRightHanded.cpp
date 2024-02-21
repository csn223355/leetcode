
/**
 * @file stringRightHanded.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-02-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// test
int main(){
    int k;
    std::string s;
    std::cin >> k;
    std::cin >> s;
    // 整体反转
    std::reverse(s.begin(),s.end());
    // 局部反转
    std::reverse(s.begin(), s.begin() + k);   ///[s.begin(),s.begin() + k)
    std::reverse(s.begin() + k, s.end());
    std::cout << s << std::endl;
    

    return 0;
}
