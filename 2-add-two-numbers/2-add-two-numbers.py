# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def addTwoNumbers(self, l1, l2):
        if (l1 == None and l2 == None):
            return None
        elif (l1 == None):
            return l2
        elif (l2 == None):
            return l1
        
        a = l1.val + l2.val
        p = ListNode(a % 10)
        p.next = self.addTwoNumbers(l1.next, l2.next)
        
        if (a >= 10):
            p.next = self.addTwoNumbers(p.next, ListNode(1))
        return p