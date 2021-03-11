# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #내가 작성한 코드
        
        if not head:
            return

        root = temp = ListNode(head.val)

        while head and head.next:
            temp.val = head.next.val
            temp.next = ListNode(head.val)
            head = head.next.next
            temp = temp.next
            if head:
                temp.next = ListNode(head.val)
            else:
                return root
            temp = temp.next
        return root