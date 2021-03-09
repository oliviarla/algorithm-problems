# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # 재귀 풀이법
        def reverse(node, prev=None):
            if not node:
                return prev
            nxt, node.next = node.next, prev
            return reverse(nxt, node)

        return reverse(head)

        # 반복 풀이법

        node, prev = head, None

        while node:
            nxt, node.next = node.next, prev  # prev를 사용해서 역방향으로 노드를 붙여나감
            prev, node = node, nxt

        return prev
