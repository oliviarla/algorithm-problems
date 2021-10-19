n = int(input())

#내가 푼 방법
d=[0]*(n+1)
d[1]=1
d[2]=2

for i in range(3, n+1):
    d[i]=(d[i-1]+d[i-2])%10007

print(d[n])

#런타임 에러를 피하기 위한 방법

d=[0,1,2]
for i in range(3, n+1):
    d.append((d[i-1]+d[i-2])%10007)

print(d[n])