# Definition for a binary tree node.
from typing import Optional, List

# 二叉树的中序遍历

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if root:
            # self.inorder_recursion(root, res)
            # self.inorder_iteration(root, res)
            self.inorder_morris(root, res)
        return res

    # 递归
    def inorder_recursion(self, node, res):
        if node:
            self.inorder_recursion(node.left, res)
            res.append(node.val)
            self.inorder_recursion(node.right, res)

    # 迭代
    def inorder_iteration(self, node, res):
        stack = [node]
        while stack:
            node = stack.pop()  # 弹出列表的最后一个元素
            if node is None:
                continue
            if isinstance(node, TreeNode):
                stack.append(node.right)  # 添加节点右子树
                stack.append(node.val)  # 添加节点的值
                stack.append(node.left)  # 添加节点左子树
            else:
                res.append(node)
        return res

    # 莫里斯中序遍历，一直找到左子树上中序遍历的最后一个元素，然后把以根为首的右子树挪到此节点下此时树接近成为一颗只有右子树的树
    def inorder_morris(self, root, res):
        while root:
            # 如果左节点不为空，就将当前节点连带右子树全部挂到
            # 左节点的最右子树下面
            if root.left:
                pre = root.left
                while pre.right:
                    pre = pre.right
                pre.right = root
                # 将root指向root的left
                tmp = root
                root = root.left
                tmp.left = None
            # 左子树为空，则打印这个节点，并向右边遍历
            else:
                res.append(root.val)
                root = root.right
        return res



t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)

t1.left = t2
t1.right = t3

s = Solution()
print(s.inorderTraversal(t1))
