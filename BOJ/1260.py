from collections import deque
n, m,v = map(int, input().split())

def main():
    # edge들 저장
    vtces = [[] for _ in range(n+1)]
    #방문 여부 확인
    visited = [False]*(n+1)
    for i in range(m):
        x, y = map(int, input().split(' '))
        #양방향 edge이므로 두 노드에 모두 저장함
        vtces[x].append(y)
        vtces[y].append(x)
        #작은 순서대로 꺼내야 하므로, 바로바로 정렬해준다
        vtces[x].sort()
        vtces[y].sort()
    dfs(vtces, v, visited)
    print()
    visited = [False]*(n+1)
    bfs(vtces, v, visited)


def dfs(vtces, start, visited):
    visited[start]=True
    print(start, end=" ")
    for i in vtces[start]:
        if not visited[i]:
            dfs(vtces, i, visited)

def bfs(vtces, start, visited):
    queue = deque()
    queue.append(start)
    visited[start]=True
    while queue:
        now = queue.popleft()
        print(now, end=" ")
        for i in vtces[now]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True

if __name__=="__main__":
    main()