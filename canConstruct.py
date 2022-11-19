import collections

# 哈希， 只统计后字符串的出现次数即可，遍历前字符串在后字符串判断
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict_magazine = collections.defaultdict(int)
        for i in magazine:
            dict_magazine[i] += 1
        for i in ransomNote:
            if i not in dict_magazine.keys():
                return False
            else:
                dict_magazine[i] -= 1
        for i in dict_magazine:
            if dict_magazine[i] < 0:
                return False
        return True

s = Solution()
str1 = "aa"
str2 = "aab"
print(s.canConstruct(str1, str2))