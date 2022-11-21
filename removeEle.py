# Definition for singly-linked list.
from typing import Optional

# 去除单链表中的指定元素，两个指针
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head is None:
            return head
        if head.val == val:
            while head and head.val == val:
                head = head.next
        if head:
            pointer = head
            next_pointer = head.next
            while next_pointer is not None:
                if next_pointer.val == val:
                    pointer.next = next_pointer.next
                    next_pointer = pointer.next
                else:
                    pointer = pointer.next
                    next_pointer = next_pointer.next
        return head


l1 = ListNode(7)
l2 = ListNode(7)
l3 = ListNode(7)
l4 = ListNode(7)
l5 = ListNode(7)
l6 = ListNode(7)
l7 = ListNode(7)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l7
l7.next = None

s = Solution()
s.removeElements(l1, 7)
