n,m = map(int, input().split())
l = []
v = [False]*9

def dfs(x):
    if x==m:
        for i in l:
            print(i, end=" ")
        print()
        return
    for i in range(1, n+1):
        if not v[i]:
            #v[i]=True
            l.append(i)
            dfs(x+1)
            l.pop()
            #v[i]=False

dfs(0)