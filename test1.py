# Definition for singly-linked list.
class ListNode:
    def __init__(self, x,nex):
        self.val = x
        self.next = nex

    def reverseList(self, head):

        if not head:
            return None
        if not head.next:
            return head
        
        cur=head
        print(cur.next.next.val)
        while(cur!=None):
            pre=cur
            nex=cur.next.next
            cur=cur.next
            cur.next=pre
            cur=nex
        return pre

c=ListNode(3,None)
b=ListNode(4,c)
a=ListNode(5,b)

a.reverseList(a)

print()