a,b = map(int, input().split())
l=[]
# 먼저 길이가 1000이 될 때까지 배열을 채운다
for i in range(1, 1001):
    for j in range(i):
        l.append(i)
        if len(l)>= 1000:
            break
# 구해진 배열에서 정수 a,b구간의 합을 구한다
print(sum(l[a-1:b]))