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
        # 내가 작성한 코드

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

        # 반복 구조로 스왑하는 풀이법
        root = prev = ListNode(None)
        prev.next = head

        while head and head.next:
            # b가 a를 가리키도록 할당
            b = head.next
            head.next = b.next
            b.next = head  # 즉 head.next -> head -> head.next.next 이런 모양이 됨

            prev.next = b  # head 이전의 값 prev에서 b로 연결

            # 다음 비교로 넘어감
            head = head.next
            prev = prev.next.next

        return root.next

        # 재귀 구조로 스왑한 풀이법

        if head and head.next:
            p = head.next
            # 스왑된 값 리턴 받음
            head.next = self.swapParis(p.next)
            p.next = head
            return p
        return head
