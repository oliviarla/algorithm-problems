# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        a = self.toList(self.reverse(l1))

    b = self.toList(self.reverse(l2))

    resultStr = int(''.join(str(e) for e in a)) + int(''.join(str(e) for e in b))

    return self.toReversedLinkedList(str(resultStr))

    def reverse(self, head):
        node, prev = head, None

        while node:
            nxt, node.next = node.next, prev  # prev를 사용해서 역방향으로 노드를 붙여나감
            prev, node = node, nxt

        return prev

    def toList(self, node):
        List = []
        while node:
            List.append(node.val)
            node = node.next
        return List

    def toReversedLinkedList(self, result):
        prev = None
        for r in result:
            node = ListNode(r)
            node.next = prev
            prev = node
        return node