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


        # dictionary를 사용한 풀이법
        nums_map={}

        for i, num in enumerate(nums):
            nums_map[num] = i #dictionary에 숫자들을 저장

        for i, num in enumerate(nums):
            if target - num in nums_map and i!=nums_map[target-num]:
                return nums.index(num), nums_map[target-num]