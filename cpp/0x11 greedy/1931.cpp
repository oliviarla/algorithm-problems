#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    pair<int, int> s[100005]; //정렬을 위해 (끝 시간, 시작 시간)으로 저장
    
    for(int i=0;i<n;i++){
        cin>>s[i].second>>s[i].first;
    }
    // 1) 끝나는 시간이 빠른 순으로 정렬
    // 2) 끝나는 시간이 같다면 시작하는 시간이 빠른 순으로 정렬 (시작하자마자 끝나는 회의 존재)
    sort(s, s+n);
    // for(int i=0;i<n;i++){
    //     cout<<s[i].second<<" "<<s[i].first<<'\n';
    // }

    int res=0;
    int t=0;
    for(int i=0;i<n;i++){ //모든 회의를 돌면서
        if(t>s[i].second) continue; //현재 시간이 회의 시작 시간 후라면 skip
        // 현재 시간이 회의 시작 전이라면 회의실 배정
        res++;
        t=s[i].first; // 회의 끝나는 시각을 현재 시간으로 둠
    }
    cout<<res;
}