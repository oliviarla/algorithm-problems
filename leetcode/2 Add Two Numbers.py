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

        # 여러 함수들로 구현한 풀이법

        # a, b 리스트에 reverse된 연결리스트의 노드들 저장
        a = self.toList(self.reverse(l1))
        b = self.toList(self.reverse(l2))

        # 리스트 내의 숫자들을 str형식에서 int로 바꾸어 결과 계산
        resultStr = int(''.join(str(e) for e in a)) + int(''.join(str(e) for e in b))

        # 결과를 다시 연결리스트로 변환
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
            prev = node  # prev를 사용해 이전 노드를 node.next에 연결되도록 함
        return node

    # 전가산기를 응용한 풀이법

    def addTwoNumbers(self, l1, l2):
        root = head = ListNode(0)

        carry = 0
        while l1 or l2 or carry:
            sum = 0
            # 두 입력값의 합 계산
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next

            # 몫과 나머지 값 계산
            carry, val = divmod(sum + carry, 10)
            head.next = ListNode(val)
            head = head.next
        return root.next
