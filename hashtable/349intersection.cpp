
/**
 * @file 349intersection.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 示例 1：
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 示例 2：
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 * 提示：
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution{
public:
    std::vector<int> intersection(std::vector<int> &nums1,std::vector<int> &nums2){
        
        std::vector<int> result; // 创建result 容器
        std::unordered_set<int> nums1_records(nums1.begin(),nums1.end()); // 创建  nums1_records 集合记录 nums1 中出现的元素
        
        for(int num : nums2){   // 如果nums2 中元素 在 nums1_records出现，则放到result 里面
            if(nums1_records.find(num) != nums1_records.end()){
                result.push_back(num);
            }
        }
        return result;
    }
    std::vector<int> intersection1(std::vector<int> &nums1,std::vector<int> &nums2){
        // 用集合来做
        std::unordered_set<int> result_set;
        std::unordered_set<int> nums1_records(nums1.begin(),nums1.end());
        
        for(int num : nums2){
            if(nums1_records.find(num) != nums1_records.end()){
                result_set.insert(num);
            }
        }
        return std::vector<int>(result_set.begin(),result_set.end());
    }
    std::vector<int> intersection2(std::vector<int> &nums1,std::vector<int> &nums2){
        // 用数组来做为hash table
        std::unordered_set<int> result_set;
        int nums1_records[1005] {0};
        for(int num : nums1){
            nums1_records[num] = 1;
        }
        for(int num : nums2){
            if(nums1_records[num] == 1){
                result_set.insert(num);
            }
        }
        return std::vector<int>(result_set.begin(),result_set.end());
    }
};
void printVector(std::vector<int> &nums){
    std::cout << "nums:";
    for(int num : nums){
        std::cout << num << ",";
    }
    std::cout << std::endl;
    
}


// test
int main(){
    std::vector<int> nums1 {4,9,5}, nums2 {9,4,9,8,4};
    Solution s1;
    auto result = s1.intersection2(nums1,nums2);
    printVector(result);
    
    return 0;
}
