n = int(input())
p = list(map(int, input().split()))

p.sort()
length = len(p)
result = 0
for i in range(len(p),0,-1):
    result += i*p[length-i]

print(result)