#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define X first
#define Y second

int main(void){
    vector<pair<int, int> > adj[20005];
    int d[20005];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;

    int V, E, st;
    cin>>V>>E>>st;

    fill(d, d+V+1, INF);
    
    int u, v, w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        //(비용, 정점) 저장
        adj[u].push_back({w,v});
    }
    // (최단거리, 정점) 저장
    d[st]=0;
    pq.push({d[st], st}); //1) 우선순위 큐에 (0,시작점) 추가

    while(!pq.empty()){ 
        auto cur = pq.top(); pq.pop(); //2) 거리가 가장 작은원소 선택
        if(d[cur.Y]!=cur.X) continue; //    저장된 비용 값이 최단 거리 테이블의 값과 다를 경우 넘어감
        for(auto nxt: adj[cur.Y]){
            //3) 다음 노드에 이미 저장된 최소거리보다 크면 넘어감
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            //  최소거리 갱신
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
        //4) 우선순위 큐 빌 때까지 반복
    }
    for(int i=1;i<=V;i++){
        if(d[i]==INF) cout<<"INF\n";
        else cout<<d[i]<<'\n';
    }
}