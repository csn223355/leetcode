/**
 * 209.长度最小的子数组
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
 * 示例：
 * 输入：s = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 提示：
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int s,vector<int> &array){ // 暴力法
        int result {INT32_MAX};   //最终结果
        int subArrayLen {0}; // 子数组长度
        size_t arraySize {array.size()}; // 数组长度
        for(size_t i{0}; i < arraySize; ++i){
            int sum {0}; // 子数组之和
            for(size_t j {i}; j < arraySize; ++j){
                sum += array[j];
                if(sum >= s){
                    subArrayLen = j - i + 1;
                    result = result < subArrayLen ? result : subArrayLen;
                    break;  //如果找到最小子數組則跳出循環
                }
            }
        }
        return result == INT32_MAX ? 0 : result;

    }
    int minSubArrayLen1(int s, vector<int> &array){  // 滑動窗口法
        int result {INT32_MAX};   //最終結果
        int subArrayLen {0};    // 子數組長度
        int sum {0};   //窗口内所有數之和
        size_t arraySize = {array.size()};
        size_t i {0}; //  i 窗口的前端
        for(size_t j{0}; j < arraySize; ++j ){    //
            sum += array[j];
            while(s < sum){    // 只要窗口里面所有数之和大于 s  窗口收缩
                subArrayLen = j - i + 1;
                result = result < subArrayLen ? result : subArrayLen;
                sum -= array[i++];
            }
        
        }
        return result == INT32_MAX ? 0 : result;
    }

};

int main(){

    vector<int> array {2,3,1,2,4,3};
    int s = 5;
    Solution s1;
    cout << "result = " << s1.minSubArrayLen1(s,array) << endl;


    return 0;
}