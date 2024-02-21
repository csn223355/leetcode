/**
 * @file 1twoSum.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/**
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]
*/




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution{
public:
    std::vector<int> twoSum(std::vector<int> nums,int target){ // 暴力法
        for(int i{0}; i < nums.size(); ++i){
            for(int j{i+1}; j < nums.size(); ++j){
                if(target == nums[i] + nums[j]){
                    return {i,j};
                }
            }
        }
        return {};
    }

    std::vector<int> twoSum1(std::vector<int> &nums,int target){ // 双指针法
    
        std::vector<int> sorted_nums {};
        std::copy(nums.begin(),nums.end(),std::back_inserter(sorted_nums));

        std::sort(sorted_nums.begin(),sorted_nums.end());
        
        int left {0};
        int right = sorted_nums.size() - 1;

        while(left < right){

            int sum{sorted_nums[left] + sorted_nums[right]};

            if(sum == target){
                int left_index = std::distance(nums.begin(),std::find(nums.begin(),nums.end(),sorted_nums[left]));
                int right_index = std::distance(nums.begin(),std::find(nums.begin(),nums.end(),sorted_nums[right]));
                if(left_index == right_index){
                    auto it_strat = nums.begin() + left_index + 1;
                    auto it_end = nums.end();
                    std::vector<int> cut_nums(it_strat,it_end);
                    int new_index = std::distance(cut_nums.begin(),std::find(cut_nums.begin(),cut_nums.end(),sorted_nums[right]));
                    right_index = new_index + left_index + 1;
                }
                return {left_index,right_index};
            }else if(sum < target){
                left ++;
            }else{
                right --;
            }

        }
            return {};
    }
    std::vector<int> twoSum2(std::vector<int> &nums,int target){  // hash 法
        std::unordered_map<int,int> record;
        for(int i{0}; i < nums.size(); ++i){
            auto it = record.find(target - nums[i]);
            if( it != record.end()){
                return {it->second,i};
            }else{
                record.insert(std::pair<int,int>(nums[i],i));
            }
        }
        return {};

    }


};

template <typename T>
void printResult(std::vector<T> nums){
    std::cout << "result:";
    for(const T &num : nums){
        std::cout << num << ",";
    }
    std::cout << std::endl;
}

// test
int main(){

    std::vector<int> nums1{2, 2, 11, 15};
    int target{4};
    Solution s1;
    auto result = s1.twoSum2(nums1,target);

    printResult(result);
    return 0;
}