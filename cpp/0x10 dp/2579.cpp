#include <bits/stdc++.h>
using namespace std;
int stair[301];
int dp[301][2];
int dp_1d[301];

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>stair[i];
    
    if(n==1){
        cout<<stair[0];
        return 0;
    }
    //////// 2차원 배열으로 푸는 방법 ////////

    // dp[0][0]=stair[0]; //가장 처음 계단 밟을 때
    // dp[0][1]=0; //가장 처음 계단 밟지 않을 때
    // dp[1][0]=stair[1]; //두번째 계단 밟을 때 (n-1번째 밟지 않음)
    // dp[1][1]=stair[0]+stair[1]; //두번째 계단 밟을 때 (n-1번째 밟음)
    // for(int i=2;i<n;i++){
    //     dp[i][0]=max(dp[i-2][0], dp[i-2][1])+stair[i]; //i-1번째 밟지 않을 때 -> i-2번째 밟았다는 의미
    //     dp[i][1]=dp[i-1][0]+stair[i]; // i-1번째 밟을 때
    // }
    // cout<<max(dp[n-1][0], dp[n-1][1]);

    ////////////////////////////////////

    //////// 1차원 배열으로 푸는 방법 ////////
    //밟지 않을 계단 총합의 최솟값을 구함
    dp_1d[0]=stair[0]; //가장 처음 계단 밟지 않음
    dp_1d[1]=stair[1]; //처음 계단 밟고 두번째 밟지 않음
    dp_1d[2]=stair[2]; //1,2번째 계단 밟고 3번째 밟지 않음

    for(int i=0;i<n;i++){
        //i-2 또는 i-3번째 밟지 않는 경우 + 현재 계단 밟지 않음
        dp_1d[i]=stair[i]+min(dp_1d[i-2], dp_1d[i-3]);
    }
    int total =0;
    for(int i=0;i<n;i++) total += stair[i];
    cout<< total- min(dp_1d[n-2], dp_1d[n-3]);
    ////////////////////////////////////
}