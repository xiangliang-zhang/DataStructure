# 字符串左翻转
class Solution:
    def reverse(self, s: str) -> str:
        return s[::-1]

    def reverseLeftWords(self, s: str, n: int) -> str:
        s = self.reverse(self.reverse(s[:n]) + self.reverse(s[n:]))
        return s


str1 = "abcdefg"
k = 2
s = Solution()
print(s.reverseLeftWords(str1, k))
