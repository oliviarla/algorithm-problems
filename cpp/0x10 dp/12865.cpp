#include <bits/stdc++.h>
using namespace std;
#define W 0
#define V 1

int n, k;
int items[105][2];
int dp[105][100005]; //dp[a][b] = c: a번째 물건까지 탐색중일 때 가방 무게가 b일 때 가방에 담긴 물건들의 가치는 c임


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    //weight, value 순으로 저장
    for(int i=1;i<=n;i++) cin>>items[i][W]>>items[i][V];
    //memset(dp, -1, sizeof(dp));

    for(int i=1;i<=n;i++){ // 아이템 1~n까지 반복
        for(int j=1;j<=k;j++){ // 가방 무게 1~k까지 반복
            // 만약 가방 무게보다 아이템 무게가 작다면 아이템을 포함/비포함 한 것 중 최대 가치 저장
            // 현 아이템 포함: [이전 아이템까지]에서 [(현재 가방 무게) - (현 아이템 무게)]의 가치+ 현 아이템 가치
            // 현 아이템 포함x: [이전 아이템][현재 가방 무게]
            if(j>=items[i][W]) dp[i][j]=max(dp[i-1][j-items[i][W]]+items[i][V], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j]; // 가방 무게보다 아이템 무게가 커 추가할 수 없으므로 이전 가치 가져옴
        }
    }
    cout<<dp[n][k];
}