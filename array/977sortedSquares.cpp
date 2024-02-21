/**
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 示例 1：
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
 * 示例 2：
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
*/

#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<int> sortedSquares(std::vector<int> &array){
        
        auto size  {array.size()};
        auto k {size - 1};
        std::vector<int> result (size ,0);
        for(size_t i{0},j{size-1}; i <= j;){
            if(array[i] * array[i] < array[j] * array[j]){
                result[k--] = array[j] * array[j];
                --j;

            }else{
                result[k--] = array[i] * array[i];
                ++i;
            }

        }
        return result;
    }

};

void printResult(const std::vector<int> &array){
    std::cout << "array:"; 
    for(const auto &it : array){
        std::cout << it << ",";
    }
    std::cout << std::endl;
}

int main(){

    std::vector<int> array = {-7,-3,2,3,11};
    Solution s1;
    auto result = s1.sortedSquares(array);
    printf("result.size(%lu)\n",result.size());
    printResult(result);



    return 0;
}