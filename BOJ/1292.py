a,b = map(int, input().split())
l=[]
for i in range(1, 1001):
    for j in range(i):
        l.append(i)
        if len(l)>= 1000:
            break
print(sum(l[a-1:b]))