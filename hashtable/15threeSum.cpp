/**
 * 
三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意： 答案中不可以包含重复的三元组。
示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
*/


/**
 * @file 15threeSum.cpp
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
#include <algorithm>
class Solution{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums){
        std::vector<std::vector<int>> result; 
        std::sort(nums.begin(),nums.end());
        for(int i{0}; i < nums.size(); ++i){
            // 出现 > 0 直接返回 
            if(nums[i] > 0){
                return result;
            }
            // 第一次去重
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            int left{i + 1};
            int right{nums.size() - 1};
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0){
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    result.push_back(std::vector<int>{nums[i],nums[left],nums[right]});
                    // 二次去重
                    while(right > left && nums[right] == nums[right-1]){right--;}
                    while(right > left && nums[left] == nums[left+1]){left++;}
                    // 找到答案时同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
        
    }
};



// test
int main(){

    std::vector<int> nums{1, 0, 1, 2, -1, -4};
    Solution solution;

    return 0;
}