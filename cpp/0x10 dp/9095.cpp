#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t, dp[11]={};
    cin>>t;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    //dp 테이블 미리 구해놓고 사용할 것!
    for(int i=4;i<11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    while(t--){
        int n;
        cin>>n;
        
        cout<<dp[n]<<"\n";
    }
}