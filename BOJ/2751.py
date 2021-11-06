n = int(input())
l = []
for i in range(n):
    l.append(int(input()))

l.sort()

for i in range(len(l)):
    print(l[i])