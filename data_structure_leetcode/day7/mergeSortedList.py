# Definition for singly-linked list.
from typing import Optional

# 合并两个有序数组

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 双指针， 代码较繁琐
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        a = list1
        b = list2
        t = ListNode()
        if a is None and b is None:
            return
        elif a is not None and b is None:
            t = a
            c = t
        elif a is None and b is not None:
            t = b
            c = t
        else:
            while a is not None and b is not None:
                if a.val <= b.val and t.next is None:
                    t = a
                    a = a.next
                    c = t
                elif a.val > b.val and t.next is None:
                    t = b
                    b = b.next
                    c = t
                elif a.val <= b.val:
                    t.next = a
                    a = a.next
                    t = t.next
                else:
                    t.next = b
                    b = b.next
                    t = t.next
            if a is not None:
                t.next = a
            if b is not None:
                t.next = b
        return c

    def mergeTwoLists_LC(self, l1: ListNode, l2: ListNode) -> ListNode:
        prehead = ListNode(-1)  # 头指针

        prev = prehead
        while l1 and l2:
            if l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next

        prev.next = l1 if l1 is not None else l2

        return prehead.next



l1 = ListNode(1)
# l2 = ListNode(2)
# l3 = ListNode(3)

# l1.next = l2
# l2.next = l3

m1 = ListNode(0)
# m2 = ListNode(2)
# m3 = ListNode(3)

# m1.next = m2
# m2.next = m3

s = Solution()
s.mergeTwoLists(l1, None)
