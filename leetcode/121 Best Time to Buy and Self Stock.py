class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        max_pt, min_pt = 0, 0
        result = []

        for i in range(1, len(prices)):
            if prices[max_pt] < prices[i]:
                max_pt = i
            elif prices[min_pt] > prices[i]:
                min_pt = i
                max_pt = i

            if min_pt < max_pt:
                result.append(prices[max_pt] - prices[min_pt])

        if result:
            return max(result)
        else:
            return 0
