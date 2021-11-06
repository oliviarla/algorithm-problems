n= int(input())
l=[]
for i in range(n):
    x,y = map(int, input().split())
    l.append((y,x))

l.sort()

for i in range(len(l)):
    print(l[i][1], l[i][0])