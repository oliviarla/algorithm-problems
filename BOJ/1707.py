from collections import deque
import sys
input = sys.stdin.readline

#이분 그래프: 두 집합으로 나누었을 때 인접 행렬이 없도록 하는, 
# 즉 두가지 색으로 겹치지 않게 그래프를 색칠할 수 있는 그래프

def main():
    k = int(input())
    for i in range(k):
        v, e= map(int, input().split())
        graph = [[] for _ in range(v+1)]
        visited = [0]*(v+1)
        bipartite=True

        for j in range(e):
            x, y = map(int, input().split())
            graph[x].append(y)
            graph[y].append(x)
        
        # 노드를 하나씩 거치면서
        for v in range(1, v+1):
            # 아직 방문하지 않은 노드를 대상으로
            if visited[v]==0:
                # BFS 해서 이분 그래프 여부 확인
                if not bfs(graph, v, visited):
                    # 이분 그래프가 될 수 없는 경우
                    bipartite = False
                    break
        
        print("YES" if bipartite else "NO")

# 인접한 노드의 색은 현재와 다른 색으로 채운다
def bfs(graph, v, visited):
    queue = deque()
    queue.append(v)
    visited[v]=1
    while queue:
        n = queue.popleft()
        for i in graph[n]:
            if visited[i]==0:
                queue.append(i)
                visited[i]= -1 * visited[n] #1, -1값을 번갈아가며 저장
            elif visited[n]==visited[i]: # 인접한 노드가 같은 값을 가지면
                return False # 이분그래프가 될 수 없으므로 False 반환
    return True


if __name__=="__main__":
    main()