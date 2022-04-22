#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int arr[100005];
    int dp[100005];
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>arr[i];

    dp[1]=arr[1];
    for(int i=2;i<=n;i++){
        dp[i]=arr[i]+dp[i-1];
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        cout<<dp[y]-dp[x-1]<<"\n";
    }
}