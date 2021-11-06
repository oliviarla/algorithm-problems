n = int(input())
l = []
for i in range(n):
    x, y = map(int, input().split())
    l.append((x,y))

l.sort()
for i in range(len(l)):
    print(l[i][0], l[i][1])