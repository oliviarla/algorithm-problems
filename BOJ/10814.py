n = int(input())
users = []
for i in range(n):
    a,b = map(str, input().split())
    users.append((int(a), i, b))
for i in sorted(users):
    print(i[0], i[2])
