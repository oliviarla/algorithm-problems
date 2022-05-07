#include <bits/stdc++.h>
using namespace std;

int n, origin[1000001], sorted[1000001];
vector<int> uniq;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    int tmp;
    /////////////////////////////////////////////
    // 방법 1) 배열 정렬 + 중복제거 직접 구현
    // for(int i=0;i<n;i++) {
    //     cin>>tmp;
    //     origin[i]=tmp;
    //     sorted[i]=tmp;
    // }
    // sort(sorted,sorted+n);

    // // 배열의 중복제거
    // for(int i=0;i<n;i++){
    //     if(i==0 || sorted[i-1]!=sorted[i]) uniq.push_back(sorted[i]);
    // }
    /////////////////////////////////////////////

    /////////////////////////////////////////////
    // 방법 2) 배열 정렬 + 중복제거 STL 사용
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>tmp;
        origin[i]=tmp;
        uniq.push_back(tmp);
    }
    sort(uniq.begin(), uniq.end());

    //STL 사용
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    /////////////////////////////////////////////


    //이분탐색
    for(int i=0;i<n;i++){
        cout<<lower_bound(uniq.begin(), uniq.end(), origin[i])-uniq.begin()<<'\n';
    }
}