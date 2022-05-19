#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int arr[100005];
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr, arr+n);

    //i가 증가함에 따라 a[j]-a[i]가 m 이상이 되는 최초의 지점 j도 증가함
    // a[j]-a[i]가 m이상이 되는 최초의 지점 j를 찾으면 그 뒤 j+1,, 확인할 필요 없음
    int en=0, min_val=0x3f3f3f3f;
    for(int st=0;st<n;st++){
        while(en<n && arr[en]-arr[st]<m) en++;
        if(en==n) break;
        min_val = min(min_val, arr[en]-arr[st]);
    }
    cout<<min_val;
}