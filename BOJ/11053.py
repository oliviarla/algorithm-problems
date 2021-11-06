n = int(input())
a = [0]
a += list(map(int, input().split()))
d=[0]*1001

answer = 0 # 전체 부분 수열 중 가장 긴 부분 증가 수열을 저장
for i in range(1, n+1):
    #현재 값을 포함하는 가장 긴 부분 증가 수열을 저장
    d[i]=1
    for j in range(i-1, 0, -1):
        if a[i]>a[j]: # 이전 인덱스들 중 현재 값보다 작은 값이 있다면
            d[i]=max(d[i], d[j]+1) # 이전 인덱스까지의 최대 부분 증가 수열 길이 + 1 저장
    answer = max(d[i], answer)
print(answer)
