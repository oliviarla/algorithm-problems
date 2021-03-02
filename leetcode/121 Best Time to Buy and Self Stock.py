class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        # 내가 작성한 코드
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

        # 저점과 현재 값과의 차이 계산을 이용한 풀이법

        profit = 0
        min_price = sys.maxsize # 시스템이 설정할 수 있는 가장 큰 값을 min_price로 선언해둠

        for price in prices:
            min_price = min(min_price, price) # 낮은 값을 찾음
            profit = max(profit, price - min_price) # '가장 작은값과 현재값의 차이' 와 기존 profit 값중 큰 값을 찾음

        return profit
