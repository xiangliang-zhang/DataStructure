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

    # 莫里斯变换，感觉没必要
    def preorder_morrios(self, root, res):
        if not root:
            return res

        p1 = root
        while p1:
            p2 = p1.left  #
            if p2:
                while p2.right and p2.right != p1:  # 无右子树
                    p2 = p2.right
                if not p2.right:
                    res.append(p1.val)
                    p2.right = p1
                    p1 = p1.left
                    continue
                else:
                    p2.right = None
            else:
                res.append(p1.val)
            p1 = p1.right

        return res

t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(4)
t5 = TreeNode(5)
t6 = TreeNode(6)
t7 = TreeNode(7)


t1.left = t2
t1.right = t3

t2.left = t4
t2.right = t5

t3.left = t6
t3.right = t7

s = Solution()
# s.preorderTraversal_recursion(t1)
# s.preorderTraversal_iteration(t1)

res = []
s.preorder_morrios(t1, res)
print(res)
