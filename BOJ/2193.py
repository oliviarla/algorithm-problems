n=int(input())
d = [[0,0] for _ in range(90)]
d[0][1]=1

for N in range(1, n):
    d[N][0]=d[N-1][0]+d[N-1][1]
    d[N][1]=d[N-1][0]

print(sum(d[n-1]))