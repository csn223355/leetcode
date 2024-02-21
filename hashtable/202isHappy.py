
#   编写一个算法来判断一个数 n 是不是快乐数。
#   「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，
#   也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
#   如果 n 是快乐数就返回 True ；不是，则返回 False 。
#   示例：

# 输入：19
# 输出：true
# 解释：
# 1^2 + 9^2 = 82
# 8^2 + 2^2 = 68
# 6^2 + 8^2 = 100
# 1^2 + 0^2 + 0^2 = 1


class Solution():

    def getSum(self,n:int)->int:      # 计算一个数的每位平方之和
        sum = 0
        while n:
            n,r = divmod(n,10)
            sum += r ** 2
        return sum
    
    def isHappy(self,n:int)->bool:
        '''
        1. 创建一个记录sum 的hash 集合
        一直循环
            2. 计算新的 sum
            3. 判断 新的 sum是否满足快乐数的条件，满足条件返回 True ,否则则 加入集合里面
            4. 更新 n
        '''
        record = set()          
        while True:
            sum = self.getSum(n)
            if sum == 1:
                return True
            
            if sum in record:
                return False
            else:
                record.add(sum)
            n = sum

    def isHappy1(self,n:int)->bool:
        '''
        1. 创建一个记录sum 的hash 集合
        2. 判断 n 是否记录hash里面
            3. 计算新的 sum
            4. 判断 新的 sum是否满足快乐数的条件，满足条件返回 True ,否则 更新 n
        5. 最终没有满足条件则返回False
        '''
        record = set()       #另外一种方案

        while n not in record:
            record.add(n)
            new_sum = sum(int(s) ** 2 for s in str(n))
            if new_sum == 1:
                return True
            else:
                n = new_sum
        return False
    
    def isHappy2(self,n:int)->bool:
        '''
        1. 创建一个纪录 sum 的 hash 集合
        2. 判断 n 是否 = 1 ，如果是 返回True 否则进行下面的循环
            3. 计算 sum 
            4. 判断sum 是否在 集合 里面 ，如果是 返回False,否则 将sum 记录在里面 
            5. 更新 n 
        '''
        record = set()       #另外一种方案
        while n != 1:
            new_sum = sum(int(i) ** 2 for i in str(n))
            if new_sum in record:
                return False
            else:
                record.add(new_sum)
            n = new_sum
        return True

        


if __name__ == "__main__":
    n = 81
    s1 = Solution()
    ret = s1.isHappy2(n)
    print(f"ret:{ret}")

            


            