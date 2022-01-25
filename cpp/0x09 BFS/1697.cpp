#include <bits/stdc++.h>
using namespace std;

int dist[100002];

int main(void){
    int n, k;
    cin>>n>>k;
    queue<int> Q;
    fill(dist, dist+100001,-1);
    dist[n]=0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int nxt:{cur+1, cur-1, cur*2}){
            if(nxt<0 ||nxt>100000) continue;
            if (dist[nxt]!=-1) continue;
            dist[nxt]=dist[cur]+1;
            Q.push(nxt);
        }
    }
    cout<<dist[k];
}