#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int parent[100005];
    queue<int> q;
    q.push(1);
    parent[1]=0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(parent[cur]==nxt) continue;
            q.push(nxt);
            parent[nxt]=cur;
        }
    }
    for(int i=2;i<=n;i++){
        cout<<parent[i]<<'\n';
    }
}