#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> adj[1005];
    
    bool vis[1005];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int nxt: adj[now]){
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt]=true;
            }
        }
        cnt++;
    }
    cout<<cnt;
}