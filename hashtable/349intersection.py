'''
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
提示：
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
'''

from typing import List

class Solution():
    def intersection(self,nums1:List[int],nums2:List[int])->List[int]:
        nums1_record = set(nums1)
        result = set()
        for i in nums2:
            if i in nums1_record:
                result.add(i)
        return list(result)
    
    def intersection1(self,nums1:List[int],nums2:List[int])->List[int]:
        return list(set(nums1) & set(nums2))
    
    def intersection2(self,nums1:List[int],nums2:List[int])->List[int]:
        result = []
        nums1_records = [0] * 1001
        nums2_records = [0] * 1001

        for i in nums1:
            nums1_records[i] += 1
        for i in nums2:
            nums2_records[i] += 1
        for i in range(1001):
            if nums1_records[i] * nums2_records[i] != 0:
                result.append(i)

        return result

        
        
        
    

if __name__ == "__main__":
    nums1 = [1,2,2,1,3]
    nums2 = [3,2,1]
    s1 = Solution()
    print(s1.intersection2(nums1,nums2))
        