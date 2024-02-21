/**
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
 * 返回它将会被按顺序插入的位置。你可以假设数组中无重复元素。
    示例 1:
    - 输入: [1,3,5,6], 5
    - 输出: 2
    示例 2:
    - 输入: [1,3,5,6], 2
    - 输出: 1
    示例 3:
    - 输入: [1,3,5,6], 7
    - 输出: 4
    示例 4:
    - 输入: [1,3,5,6], 0
    - 输出: 0
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int searchInsert(vector<int> &nums,int target){ //方法1 暴力法
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] >= target){
                return i;
            }
        }
        return nums.size();
    }
    int searchInsert1(vector<int> &nums,int target){ //方法2 二分法
        int l = 0;
        int r = nums.size() - 1;   // 定义target在左闭右闭的区间里，[left, right]
        while(l <= r){  // 当left==right，区间[left, right]依然有效
            int mid = l + (r - l) / 2;  // 防止溢出 等同于(left + right)/2
            if(nums[mid] > target){     // target 在左区间，所以[left, middle - 1]
                r = mid - 1;
            }
            else if(nums[mid] < target){ // target 在右区间，所以[middle + 1, right]
                l = mid + 1;
            }else{
                return mid; // nums[middle] == target
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
        return r + 1;
    }
};


int main(){

    vector<int> nums = {1,3,5,6};
    int target = 0;
    Solution s1;
    int result = s1.searchInsert1(nums,target);
    cout << "result:" << result << endl;
    return 0;
}