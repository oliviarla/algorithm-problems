class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # 내가 작성한 코드
        nums.sort()
        result = 0

        for i in range(len(nums) // 2):
            print(nums[2 * i], nums[2 * i + 1])
            result += min(nums[2 * i], nums[2 * i + 1])

        return result

        # 짝수인덱스의 값만 더하면 되는 패턴을 이용한 코드
        nums.sort()
        result = 0

        for i, n in enumerate(nums):
            if i % 2 == 0:
                result += n

        return result

        # 한줄로 풀이하는 파이썬다운 코드

        return sum(sorted(nums)[::2])
