class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        anagram = collections.defaultdict(list) #딕셔너리 생성
        for word in strs:
            anagram[''.join(sorted(word))].append(word) #word를 정렬한 것은 key값으로, word는 value값으로 추가
            #동일한 키를 가지면 동일한 알파벳들로 구성된 단어이므로 anagram임을 알 수 있음
        return anagram.values() #정렬된 key값에 대응하는 value값 반환 