/**
18题. 四数之和
题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：
答案中不可以包含重复的四元组。
示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]
*/


/**
 * @file 18fourSum.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-04
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
    std::vector<std::vector<int>> fourSum(std::vector<int> nums, int target){
        std::vector<std::vector<int>> result;
        int len = nums.size();

        if(len < 4){
            return result;
        }

        std::sort(nums.begin(),nums.end());

        for(int j{0}; j < len - 3; ++j){

            if(nums[j] > 0 && nums[j] > target){break;}
            // 一次去重
            if(j > 0 && nums[j] == nums[j-1]){continue;}
            
            for(int i{j+1}; i < len - 2; ++i){

                if(nums[j] + nums[i] > 0 && nums[j] + nums[i] > target){break;}
                // 二次去重
                if(i > j + 1 && nums[i] == nums[i-1]){continue;}

                int left{i + 1};
                int right{len-1};
                while(left < right){
                    int sum {nums[j] + nums[i] + nums[left] + nums[right] };
                    if(sum > target){
                        right--;
                    }else if (sum < target){
                        left++;
                    }else{
                        result.push_back(std::vector<int>{nums[j],nums[i],nums[left],nums[right]});
                        // 三次去重
                        while(left < right && nums[right] == nums[right - 1]){right--;}
                        while(left < right && nums[left] == nums[left + 1]){left++;}
                        // 找到之后更新 两边端点
                        left++;
                        right--;
                    }
                }
            }


        }
        return result;
    }
};


// test
int main(){

    return 0;
}
