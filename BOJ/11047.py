n,k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))

result = 0
for i in reversed(coins):
    while k>=i:
        k-=i
        result +=1
print(result)