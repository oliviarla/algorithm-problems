class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        # 내가 작성한 코드
        # time limit exceeded 발생

        # result = []
        # for i in range(len(nums) - 2):
        #     for j in range(i + 1, len(nums) - 1):
        #         for k in range(j + 1, len(nums)):
        #             if nums[i] + nums[j] + nums[k] == 0:
        #                 num_list = sorted([nums[i], nums[j], nums[k]])
        #                 if num_list not in result:
        #                     result.append(num_list)
        # return result

        # Two pointer를 사용한 풀이법

        result = []
        nums.sort()  # 먼저 nums 리스트를 정렬한다

        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue  # nums가 정렬되었으므로 중복된 값을 제거할 수 있음

            left, right = i+1, len(nums) - 1  # nums[i]이후의 값들 중에서 왼쪽, 오른쪽 포인터 설정
            while left < right:
                sum = nums[i] + nums[left] + nums[right]

                if sum < 0:  # 합이 0보다 작으면 더 큰 값을 더하기 위해 왼쪽 포인터를 한칸 이동
                    left += 1
                elif sum > 0:  # 합이 0보다 크면 더 작은 값을 더하기 위해 오른쪽 포인터를 한칸 이동
                    right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])

                    while left < right and nums[left] == nums[left + 1]:  # 중복제거
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:  # 중복제거
                        right -= 1

                    # 다음 sum 값을 계산하기 위해 포인터 이동
                    left += 1
                    right -= 1
        return result