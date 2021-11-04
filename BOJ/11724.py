import sys
input = sys.stdin.readline

def main():
    n,m= map(int, input().split())
    graph = [[]for _ in range(n+1)]
    for _ in range(m):
        x,y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
    visited = [False]*(n+1)
    res = 0
    for i in range(1, n+1):
        if not visited[i]:
            dfs(graph, i, visited) #방문되지 않은 노드들을 dfs로 방문처리
            res +=1 #한번 dfs돌릴 때 한번의 connect component 생성됨
    print(res)

def dfs(graph, v, visited):
    visited[v]=True
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

if __name__=="__main__":
    main()