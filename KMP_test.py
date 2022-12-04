# KMP， 根据王道考研书推导得到的结果，并不是直接得出的，便于理解
def get_next(testStr):
    nextVal = [0]
    i = 0
    j = 1
    while j < len(testStr):
        if testStr[j] == testStr[i]:
            nextVal.append(i + 1)
            i += 1
            j += 1
        else:
            if i == 0:
                nextVal.append(0)
                j += 1
            else:
                i = nextVal[i - 1]
    print("orginal next list:", nextVal)
    nextVal.pop()
    nextVal.insert(0, -1)
    print("move right 1 position: ", nextVal)
    nextVal = [i + 1 for i in nextVal]
    print("all add 1:", nextVal)

    for j in range(1, len(nextVal)):
        if testStr[j] == testStr[nextVal[j] - 1]:
            nextVal[j] = nextVal[nextVal[j] - 1]
    print("optimized res:", nextVal)
    return nextVal


def KMP_test(mainStr, testStr, nextVal):
    i = 0
    j = 0
    while i < len(mainStr) and j < len(testStr):
        if mainStr[i] == testStr[j]:
            i += 1
            j += 1
        else:
            j = nextVal[j] - 1

    if j == len(testStr):
        return i - len(testStr)


mainStr = "ababcabcacbab"
testStr = "aaab"
test2Str = "abaabc"
test3Str = "abaabcaba"
test4Str = "ababaaababaa"
test5Str = "abcac"
nextVal = get_next(test5Str)
res = KMP_test(mainStr, test5Str, nextVal)
print("起始位置为:", res)
