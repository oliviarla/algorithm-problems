class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        output = []

        # 자신을 제외한 왼쪽의 값을 곱해 p에 저장한 후 output 값에 적용
        p = 1
        for i in range(0, len(nums)):
            output.append(p)
            p = p * nums[i]

        # 자신을 제외한 오른쪽의 값을 점차 곱해 p에 저장한 후 output 값에 적용
        p = 1
        for k in range(len(nums) - 1, 0 - 1, -1):
            output[k] = output[k] * p
            p = p * nums[k]

        return output
