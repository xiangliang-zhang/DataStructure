# 用队列实现栈
class MyQueue:

    def __init__(self):
        self.ele = []

    def push(self, x: int) -> None:
        self.ele.append(x)

    def pop(self) -> int:
        t = self.ele.pop(0)
        return t

    def peek(self) -> int:
        if self.empty():
            return None
        else:
            return self.ele[0]

    def empty(self) -> bool:
        if len(self.ele) == 0:
            return True
        else:
            return False


x1 = 5
x2 = 6
obj = MyQueue()
obj.push(x1)
obj.push(x2)
param_2 = obj.pop()
param_3 = obj.peek()
param_4 = obj.empty()
