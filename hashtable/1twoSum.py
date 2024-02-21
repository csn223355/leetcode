'''
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]
'''
from typing import List
class Solution():
    def twoSum(self,nums:List[int],traget:int)->List[int]:
        '''
        hash法 用字典作为hashtable
        '''
        record = dict()
        for i in nums:
            num = traget - i
            if num in record:
                return [record[num],nums.index(i)]
            else:
                record[i] = nums.index(i)
        return []
    def twoSum1(self,nums:List[int],traget:int)->List[int]:
        '''
        双指针
        '''
        sorted_nums = sorted(nums)
        left = 0
        right = len(sorted_nums) - 1
        while left < right:
            new_sum = sorted_nums[left] + sorted_nums[right]
            if new_sum == traget:
                left_index = nums.index(sorted_nums[left])    # index方法，默认寻找的是元素第一次出现的索引
                right_index = nums.index(sorted_nums[right])
                if left_index == right_index:
                    right_index = nums[left_index+1:].index(sorted_nums[right]) + left_index + 1
                return [left_index,right_index]
            elif new_sum < traget:
                left += 1
            else:
                right -= 1
        return []

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    traget = 9
    s1 = Solution()
    result = s1.twoSum1(nums,traget)
    print("result:",result)
