import collections
from collections import defaultdict


class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt_dict = defaultdict(int)
        for i in s:
            cnt_dict[i] += 1
        for item in cnt_dict.keys():
            if cnt_dict[item] == 1:
                return s.index(item)
        return -1

    # leetcode第三种方法， 简称垃圾，麻烦、不直观
    def firstUniqChar_queue(self, s: str) -> int:
        position = dict()
        q = collections.deque()
        for i, ch in enumerate(s):
            if ch not in position:
                position[ch] = i
                q.append((s[i], i))
            else:
                position[ch] = -1
                while q and position[q[0][0]] == -1:
                    q.popleft()
        return -1 if not q else q[0][1]


s = Solution()
t = "leetcode"
s.firstUniqChar_queue(t)
