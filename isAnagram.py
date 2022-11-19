import collections
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_dict = collections.defaultdict(int)
        for i in s:
            s_dict[i] += 1
        for i in t:
            if i not in s:
                return False
            else:
                s_dict[i] -= 1
        for i in s_dict.values():
            if i != 0:
                return False
        return True

s = Solution()
str1 = "rat"
str2 = "car"
print(s.isAnagram(str1, str2))
