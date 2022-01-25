#include <bits/stdc++.h>
using namespace std;
//DP 문제 푸는 과정
//1. 테이블 정의하기
//2. 점화식 찾기
//3. 초기값 정의하기
int dp[1000005];
int main(void){
    int n;
    cin>>n;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1; //먼저 -1한 연산 횟수를 저장
        if(i%3==0) dp[i]=min(dp[i/3]+1, dp[i]); //3의 배수라서 연산 횟수가 줄어든다면 갱신
        if(i%2==0) dp[i]=min(dp[i/2]+1, dp[i]); //2의 배수라서 연산 횟수가 줄어든다면 갱신
    }
    cout<<dp[n];
}