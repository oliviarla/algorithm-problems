l=[]
max_len = 0
for _ in range(5):
    new = list(input())
    l.append(new)
    # 입력받은 문자열 중 가장 긴 문자열의 길이 저장
    max_len = max(max_len, len(new))

for i in range(max_len): #가장 긴 문자열의 길이까지
    for r in l: # 각 문자열마다
        if len(r)>i: # 인덱스 0부터 출력
            print(r[i], end="")