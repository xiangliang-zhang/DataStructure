# Definition for a binary tree node.
from typing import Optional, List


# 先序遍历二叉树，递归
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    # 递归
    def preorderTraversal_recursion(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        t = root
        self.preorder(t, res)
        return res

    def preorder(self, t, res):
        if t is not None:
            res.append(t.val)
            self.preorder(t.left, res)
            self.preorder(t.right, res)

    # 迭代
    def preorderTraversal_iteration(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if not root:
            return res
        t = root
        stack = []
        while stack or t:
            while t:
                res.append(t.val)
                stack.append(t)
                t = t.left
            t = stack.pop()
            t = t.right

        return res


t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)

t1.right = t2
t2.left = t3

s = Solution()
# s.preorderTraversal_recursion(t1)
s.preorderTraversal_iteration(t1)
