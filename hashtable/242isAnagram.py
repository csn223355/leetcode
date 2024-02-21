'''
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
示例 2: 输入: s = "rat", t = "car" 输出: false
说明: 你可以假设字符串只包含小写字母。
'''




class Solution():
    def isAnagram(self,s:str,t:str)->bool:
        record = [0]*26
        for i in s:
            record[ord(i) - ord('a')] += 1
        for i in t:
            record[ord(i) - ord('a')] -= 1
        for i in record:
            if i != 0:
                return False
        return True
    def isAnagram1(self,s:str,t:str)->bool:
        from collections import Counter
        s_counter = Counter(s)
        t_counter = Counter(t)
        if s_counter == t_counter:
            return True
        else:
            return False
    def isAnagram2(self,s:str,t:str)->bool:
        from collections import defaultdict
        
        s_dict = defaultdict(int)
        t_dict = defaultdict(int)
        
        for i in s:
            s_dict[i] += 1
        
        for i in t:
            t_dict[i] += 1
        
        if t_dict == s_dict:
            return True
        else:
            return False


if __name__ == "__main__":
    s ="anagram"
    t = "nagaram"
    # s,t = "rat", "car"
    s1 = Solution()
    ret = s1.isAnagram2(s,t)
    print("ret:{0}".format(ret))
    pass