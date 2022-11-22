# Definition for singly-linked list.
from typing import Optional

# 删除单链表中的重复元素，两指针
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        else:
            cur_pointer = head
            next_pointer = head.next
            while next_pointer is not None:
                if cur_pointer.val == next_pointer.val:
                    cur_pointer.next = next_pointer.next
                    next_pointer = cur_pointer.next
                else:
                    cur_pointer = cur_pointer.next
                    next_pointer = next_pointer.next

            return head


l1 = ListNode(1)
l2 = ListNode(1)
l3 = ListNode(2)

l1.next = l2
l2.next = l3

s = Solution()
s.deleteDuplicates(l1)
