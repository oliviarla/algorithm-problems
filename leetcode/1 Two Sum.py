class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(len(nums)): #i를 제외한 인덱스에서 target-nums[i]가 존재하는지 확인
                if nums[j]==target-nums[i] and i!=j:
                    return i, j