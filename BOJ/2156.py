n = int(input())
a = []
d = [0]*10000
for i in range(n):
    a.append(int(input()))

d[0]=a[0]
for i in range(1, n):
    #i 마심
        # i-1 안마심 -> (i-2까지의 최대) + i
        # i-1 마심 -> (i-3까지의 최대) + (i-1) + i
    # i 안마심 -> d[i-1]
    d[i]=max(d[i-2]+a[i], d[i-3]+a[i-1]+a[i], d[i-1])
print(d[n-1])