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
            v[i]=True
            l.append(i)
            dfs(x+1)
            l.pop()
            v[i]=False

dfs(0)