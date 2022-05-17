#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int solution(int N, vector<vector<int> > road, int K) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    const int INF = 0x3f3f3f3f;
    
    int d[53];
    vector<pair<int, int>> adj[51];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(auto e: road){
        adj[e[0]].push_back({e[2], e[1]});
        adj[e[1]].push_back({e[2], e[0]});
    }
    
    fill(d, d+N+1, INF);
    
    d[1]=0;
    pq.push({d[1], 1});
    
    while(!pq.empty()){
        auto cur = pq.top();pq.pop();
        if(d[cur.Y]!=cur.X) continue;
        for(auto nxt:adj[cur.Y]){
            if(d[nxt.Y]<=d[cur.Y]+nxt.X) continue;
            d[nxt.Y]=d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    
    int answer = 0;
    
    for(int i=1;i<=N;i++){
        cout<<d[i]<<' ';
        if(d[i]<=K) answer++;
    }
    
    return answer;
}