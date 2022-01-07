#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, num[100001], x;
    int ans = 0;
    bool occr[2000001]; //자연수의 존재 여부
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cin>>x;

    for(int i=0;i<n;i++){
        if (x-num[i]>0 && occr[x-num[i]]) ans++; // 현재 값에서 더해질 값이 양수여야 하므로 x-num[i]체크
        occr[num[i]]=true; // 존재 여부 배열 업데이트
    }

    cout<<ans<<'\n';
    return 0;
}