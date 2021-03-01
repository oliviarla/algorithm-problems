class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        max_pt, min_pt = 0, 0

        for i in range(len(prices)):
            if prices[max_pt] < prices[i]:
                max_pt = i
            elif prices[min_pt] > prices[i]:
                min_pt = i
