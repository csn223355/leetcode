/**
 * 第454题.四数相加II
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

例如:

输入:

A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:

2

解释:

两个元组如下:

(0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
(1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

*/


/**
 * @file 454fourSumCount.cpp
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
#include <unordered_map>

class Solution{
public:
    int forSumCount(const std::vector<int> &A, const std::vector<int> &B,const std::vector<int> &C, const std::vector<int> &D){
        std::unordered_map<int,int> record;    //记录 A B 两个数组之和，出现的次数
        for(auto a:A){
            for(auto b:B){
                record[a + b]++;
            }
        }
        int count{0};
        for(auto c:C){
            for(auto d:D){
                if( record.find(0 - (c + d)) != record.end()){
                    count += record[0 - (c+d)];
                }
            }
        }
        return count;
    }
};


// test
int main(){
    std::vector<int> A{1, 2, 2},B{-2,-1 , 3},C{-1, 2, 1},D{0, 2, 3};
    Solution s1;
    int ret = s1.forSumCount(A,B,C,D);
    std::cout << "ret:" << ret << std::endl;


    return 0;
}