/**
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 * 示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。
 * 示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
*/

#include <iostream>
#include <vector>


class Solution{

public:
    size_t moveElement(std::vector<int> &array ,int target){ // 暴力法
        size_t size {array.size()};
        for(size_t i {0}; i < size; ++i){
            if(array[i] == target){
                for(size_t j {i}; j < size; ++j){
                    array[j] = array[j + 1];    
                }
                --i;
                --size;
            }
        }
        return size;
    }
    size_t moveElement1(std::vector<int> &array ,int target){ // 双指针法
        size_t size {array.size()};
        size_t fast{0},low{0};
        for(fast; fast < size; ++fast){
            if(array[fast] != target){       // 如果当前值 != target :  array[low] = array[fast];
                array[low] = array[fast];   // fast 指向新数组需要获得的元素； 慢指针指向获得我们新数组需要更新的位置
                ++low;
            }
        }
        return low;

        
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

    std::vector<int> array {0,1,2,2,3,0,4,2};
    int target {2};
    Solution s1;
    std::cout << "result:" << s1.moveElement(array,target) << std::endl;
    // printResult(array);


    return 0;
}