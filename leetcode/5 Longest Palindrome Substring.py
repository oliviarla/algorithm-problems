class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) < 2 or s == s[::-1]:  # s의 길이가 2보다 작거나 s가 뒤집어도 같은 문자열이면
            return s  # s를 그대로 반환

        def expand(left, right):
            while left >= 0 and right <= len(s) and s[left] == s[right - 1]:
                left -= 1
                right += 1
                return s[left + 1:right - 1]

        result = ''
        for i in range(len(s) - 1):
            result = max(result,
                         expand(i, i + 1),
                         expand(i, i + 2)
            key = lambda n: len(n))
            return result