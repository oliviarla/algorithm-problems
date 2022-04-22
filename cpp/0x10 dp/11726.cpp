#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, dp[1001];
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2]%10007; //계산 중간중간에 나눠주어야 int overflow 방지
    cout<<dp[n]%10007;
}