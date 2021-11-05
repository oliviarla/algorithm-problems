n,m = map(int, input().split())
l = []
v = [False]*9

def f(x):
    if x==m:
        for i in l:
            print(i, end=" ")
        print()
        return
    
    for i in range(1, n+1):
        if not v[i]:
            v[i]=True
            l.append(i)
            f(x+1)
            l.pop()
            v[i]=False

def main():
    
    f(0)

if __name__ =="__main__":
    main()