#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
stack<int> s;
bool vis_dfs[1005]={0,};

void dfs(int cur){
    vis_dfs[cur]=true;
    cout<<cur<<' ';
    for(auto nxt: adj[cur]){
        if(vis_dfs[nxt]) continue;
        dfs(nxt);
    }
}

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
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    cout<<'\n';

    //bfs
    queue<int> q;
    bool vis[1005]={0,};

    q.push(v);
    vis[v]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<' ';
        for(auto nxt: adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt]=true;
        }
    }
}