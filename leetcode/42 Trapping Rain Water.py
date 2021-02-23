class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        # 내가 작성한 코드
        # 런타임 에러 발생

        '''
        water = 0
        left_pt = 0
        right_pt = 0

        for i in range(1, len(height)):
            if height[left_pt] <= height[i]:  # 왼쪽 포인터의 값이 현재 값보다 작거나 같으면
                if left_pt < right_pt:
                    for k in range(left_pt + 1, right_pt + 1):
                        water += height[left_pt] - height[k]
                left_pt = i

            elif height[left_pt] > height[i]:
                right_pt = i

            if height[left_pt] > max(height[left_pt + 1:]):
                left_pt = i

        return water
        '''

        volume = 0  # 물의 부피
        left, right = 0, len(height) - 1  # 양 끝부터 포인터 이동
        left_max, right_max = height[left], height[right]

        while left < right:
            left_max, right_max = max(height[left], left_max), max(height[right], right_max)

            # 더 높은 쪽을 향해 포인터를 이동시킴
            if left_max <= right_max:
                volume += left_max - height[left]
                left += 1
            else:
                volume += right_max - height[right]
                right -= 1
        return volume