class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        digits, letters = [], []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)

        #람다식을 사용한 정렬
        #letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))

        #람다식을 사용하지 않은 정렬
        def sort_log(x):
            return x.split()[1:], x.split()[0] #문자가 동일할 경우 식별자 순으로 정렬
        
        letters.sort(key=sort_log)
        
        return letters + digits