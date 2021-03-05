# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import collections


class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        # 데크를 활용한 풀이법
        q = collections.deque()

        if not head:
            return True

        node = head
        while node is not None:
            q.append(node.val)  # 리스트에 노드의 값을 저장
            node = node.next  # 저장 후 다음 노드로 이동

        while len(q) > 1:
            if q.popleft() != q.pop():  # 맨 앞과 뒤의 값을 비교하여 다르면 False 반환
                return False

        return True

        # 런너를 이용한 풀이법
        rev = None  # 역순 연결 리스트 rev 생성
        slow = fast = head  # 빠른 런너와 느린 런너 모두 head에서 시작

        while fast and fast.next:
            fast = fast.next.next  # 빠른 런너는 두 노드씩 이동
            rev, rev.next, slow = slow, rev, slow.next  # slow는 다음 노드로 이동하고, rev는 현재 slow값에서 이전 rev값들로 연결되는 리스트로 수정

        if fast:
            slow = slow.next  # 홀수일 때 중앙에 위치한 값은 비교에서 제외되어야 하므로 slow를 한칸 더 이동시킴

        # 팰린드롬 여부 확인
        while rev and rev.val == slow.val:
            slow, rev = slow.next, rev.next  # 중간지점 이후부터 움직이는 slow 런너와 역순을 기록한 rev 연결 리스트를 비교

        return not rev  # rev가 끝까지 이동하여 None이면 true, None이 아니면 false를 반환

