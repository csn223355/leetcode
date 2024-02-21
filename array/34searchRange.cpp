/**

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？
示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
*/

#include<iostream>
#include<vector>
#include "utils.hpp"

using namespace std;

class Solution{
public:
	//TODO
	vector<int> searchRange(const vector<int>& nums, int target) {
        int leftBorder = getleftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // 情况一
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        // 情况三
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        // 情况二
        return {-1, -1};
    }
    std::vector<int> searchRange1(const std::vector<int> &nums, int target){
        int ret = binarySearch(nums, target);
        if(ret == -1){
            return {-1, -1};
        }
        int l {ret}, r {ret};
        while(l > 0 && nums[l] == nums[l - 1]){
            --l;
        }
        while(r < nums.size() && nums[r] == nums[r + 1]){
            ++r;
        }
        return {l, r};
    }

private:
		// 二分查找，寻找target的右边界（不包括target）
		// 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
    int getRightBorder(const vector<int>& nums, int target){   //寻找右边界
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int rightBorder = -2;  // 记录一下rightBorder没有被赋值的情况
        while(l <= r){  // 定义target在左闭右闭的区间里，[left, right]
            int mid = l + (r - l) / 2;
            if(nums[mid] > target ){ //target 在左区间   
                r = mid - 1; //更新区间[l,mid-1]
            }else{ // 当nums[middle] <= target的时候，更新left，这样才能得到target的右边界
                l = mid  + 1;
                rightBorder = l;
            }
        }
        return rightBorder;
    }
		// 二分查找，寻找target的左边界leftBorder（不包括target）
		// 如果leftBorder没有被赋值（即target在数组范围的右边，例如数组[3,3],target为4），为了处理情况一
    int getleftBorder(const vector<int>& nums, int target){   //寻找左边界
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int leftBorder = -2;  // 记录一下rightBorder没有被赋值的情况
        while(l <= r){  // 定义target在左闭右闭的区间里，[left, right]
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target ){  // 寻找左边界，就要在nums[middle] >= target的时候更新right  
                r = mid  - 1;
                leftBorder = r;
            }else{ // 当nums[middle] <= target的时候，更新left，这样才能得到target的右边界
                l = mid + 1;
            }
        }
        return leftBorder;
    }
    int binarySearch(const std::vector<int> &nums, int target){
        int l {0};
        int r {nums.size() - 1};
        while(l <= r){
            int mid {l + (r - l) / 2};
            if(nums[mid] > target){
                r = mid - 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    
};


int main(){
    std::vector<int> nums = {1,2,2,2,2,2,2,2,2,3,4,5,6,7};
    int target {2};
    Solution solution;
    auto ret = solution.searchRange(nums, target);
    printVector(ret);
    return 0;
}
