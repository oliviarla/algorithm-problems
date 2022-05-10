#include <bits/stdc++.h>
using namespace std;

// O(N^2 lgN) 풀이
// a[i]+a[j]의 경우의 수를 모두 구해 two 배열에 저장
// two배열에 a[l]- a[k]: (3개총합)-(세번째수) 존재하는지 확인
// 존재하면? a[l]이 max보다 크면 max 갱신

// 모범답안)
// 만약 u 배열을 미리 정렬하였다면 l을 n-1부터 돌면서 
// 가장 먼저 찾은 u[l]값을 출력하면 됨

int n, u[1005];
vector<int> two;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++) cin>>u[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            two.push_back(u[i]+u[j]);
        }
    }
    sort(two.begin(), two.end());
    int ans =0;
    for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            if(binary_search(two.begin(), two.end(), u[l]-u[k])){
                ans = max(u[l], ans);
            }
        }
    }
    cout<<ans;
}