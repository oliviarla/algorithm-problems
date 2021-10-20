n = int(input())

d = [[1 for _ in range(10)]for _ in range(1000)]

for N in range(1, n):
    for i in range(0, 10):
        d[N][i]=sum(d[N-1][:i+1])

print(sum(d[n-1])%10007)