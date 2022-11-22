
# 括号匹配， 栈
class Solution:
    def isValid(self, s: str) -> bool:
        temp = []
        for i in s:
            if i in ['(', '[', '{']:
                temp.append(i)
            else:
                if len(temp) == 0:
                    return False
                elif i == ')' and temp.pop() != '(':
                    return False
                elif i == ']' and temp.pop() != '[':
                    return False
                elif i == '}' and temp.pop() != '{':
                    return False
        if len(temp) == 0:
            return True
        else:
            return False


test1 = ""
test2 = "([])"
test3 = "(]"
test4 = "()[]{}"
test5 = "([)]"
test6 = "(())"
test7 = "[()]"
test8 = "["
test9 = "]"

s = Solution()

print(s.isValid(test1))
print(s.isValid(test2))
print(s.isValid(test3))
print(s.isValid(test4))
print(s.isValid(test5))
print(s.isValid(test6))
print(s.isValid(test7))
print(s.isValid(test8))
