/**
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，
 * 也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
 * 如果 n 是快乐数就返回 True ；不是，则返回 False 。
 * 示例：

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>


class Solution{
public:
    int getSum(int n){   // 计算一个数的每位的平方之和
        int sum{0};
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n){
        std::unordered_set<int> records;     // 用一个集合来做hash表
        while(1){                               // 将计算好的 数的每位的平方之和 放到集合里面 如果出现重复的就不是快乐数
            int sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(records.find(sum) != records.end()){
                return false;
            }else{
                records.insert(sum);
            }
            n = sum;
        }
        
    }
};

int main(){

    Solution s1;
    int n {19};
    bool ret = s1.isHappy(n);
    std::cout << "ret:" << ret << std::endl;
    return 0;
}
