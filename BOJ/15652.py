n,m = map(int, input().split())
l = []
v = [False]*9

def dfs(x):
    if x==m:
        ascend=True
        for i in range(len(l)-1):
            if l[i]>l[i+1]:
                ascend = False
        if ascend:
            for i in l:
                print(i, end=" ")
            print()
        return
    for i in range(1, n+1):
        if not v[i]:
            l.append(i)
            dfs(x+1)
            l.pop()

dfs(0)