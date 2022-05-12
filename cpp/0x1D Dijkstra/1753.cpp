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
    pq.push({d[st], st});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y]!=cur.X) continue;
        for(auto nxt: adj[cur.Y]){
            //다음 노드에 이미 저장된 최소거리보다 크면 넘어감
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            //최소거리 갱신됨
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    for(int i=1;i<=V;i++){
        if(d[i]==INF) cout<<"INF\n";
        else cout<<d[i]<<'\n';
    }
}