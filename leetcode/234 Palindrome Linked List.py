# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        q = []

        if not head:
            return True

        node = head
        while node is not None:
            q.append(node.val)  # 리스트에 노드의 값을 저장
            node = node.next  # 저장 후 다음 노드로 이동

        while len(q) > 1:
            if q.pop(0) != q.pop():  # 맨 앞과 뒤의 값을 비교하여 다르면 False 반환
                return False

        return True
