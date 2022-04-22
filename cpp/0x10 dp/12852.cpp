#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, dp[1000001], cp[1000001];
    cin>>n;
    
    dp[1]=0; //1을 1로만드려면 0회 필요
    dp[2]=1;
    dp[3]=1;
    
    cp[1]=0;
    cp[2]=1;
    cp[3]=1;

    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+1;
        cp[i]=i-1;
        if(i%3==0&&dp[i]>dp[i/3]){
            dp[i]=dp[i/3]+1;
            cp[i]=i/3;
        }
        if(i%2==0&&dp[i]>dp[i/2]){
            dp[i]=dp[i/2]+1;
            cp[i]=i/2;
        }
    }
    cout<<dp[n]<<'\n';
    int cur=n;
    while(true){
        cout<<cur<<' ';
        if(cur==1) break;
        cur=cp[cur];
    }
}