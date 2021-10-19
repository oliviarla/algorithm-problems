n = int(input())

d=[9]

for i in range(1, n):
    d.append((d[i-1]*2-i)%1000000000)

print(d[n])