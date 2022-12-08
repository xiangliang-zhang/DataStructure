# Definition for singly-linked list.
from typing import Optional

# 判断是否是环形链表

# 快慢指针，慢走1，快走2
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while slow != None and fast != None:
            slow = slow.next
            if fast.next:
                fast = fast.next.next
            else:
                break
            if slow == fast:
                return True
        return False


node_list = [3, 2, 0, -4, 5]
l1 = ListNode(3)
l2 = ListNode(2)
l3 = ListNode(0)
l4 = ListNode(-4)
l5 = ListNode(5)

l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
# l4.next = l2


s = Solution()
print(s.hasCycle(l1))
