# Definition for singly-linked list.
from typing import Optional


# 反转链表, 三指针
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        elif head.next is None:
            return head
        elif head.next.next is None:
            temp_pointer = head.next
            temp_pointer.next = head
            head.next = None
            head = temp_pointer
            return head
        else:
            temp_pointer = head
            cur_pointer = head.next
            next_pointer = cur_pointer.next
            while cur_pointer is not None:
                cur_pointer.next = temp_pointer
                head.next = None
                temp_pointer = cur_pointer
                cur_pointer = next_pointer
                if cur_pointer:
                    next_pointer = cur_pointer.next
                else:
                    next_pointer = None
            head = temp_pointer
            return head

l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)

l1.next = l2
l2.next = l3
l3.next = l4

s = Solution()
s.reverseList(l1)