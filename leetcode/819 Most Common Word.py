import collections


class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        for i in range(len(paragraph)):
            if not paragraph[i].isalnum():
                paragraph = paragraph.replace(paragraph[i], ' ')
        words = paragraph.lower().split()

        max_count = 0
        max_word = ''
        for i in words:
            if i not in banned:
                if words.count(i) > max_count:
                    max_count = words.count(i)
                    max_word = i
        return max_word

        #최적화 코드
        # words = [word for word in re.sub(r'[^\w]', ' ', paragraph)
        #     .lower().split()
        #          if word not in banned]
        #
        # counts = collections.Counter(words)
        # return counts.most_common()[0][0]


