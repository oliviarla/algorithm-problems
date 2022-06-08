#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis_dfs[1005] ={0,};
bool vis_bfs[1005] ={0,};

int main(void){
    int n, m, v;
    cin>>n>>m>>v;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    //dfs
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vis_dfs[cur]) continue;
        vis_dfs[cur]=true;
        cout<<cur<<' ';
        for(auto nxt: adj[cur]){
            //cout<<nxt<<' ';
            s.push(nxt);
        }
    }
    cout<<'\n';

    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    queue<int> q;
    q.push(v);
    vis_bfs[v]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<' ';
        for(int nxt: adj[cur]){
            if(vis_bfs[nxt]) continue;
            q.push(nxt);
            vis_bfs[nxt]=true;
        }
    }
}