#include <bits/stdc++.h>
using namespace std;
int n, m, arr[500005], t;

int lower_idx(int target, int len){
    int st=0;
    int en=len;
    while(st<en){
        int mid=(st+en)/2;
        //mid 값과 target 값이 같더라도 en을 mid로 이동시켜 평균낼 수 있도록 하여 가장 앞부분의 target 값을 찾음
        if(arr[mid]>=target) en=mid;
        else st=mid+1;
    }
    return st;
}

int upper_idx(int target, int len){
    int st=0;
    int en = len;
    while(st<en){ 
        int mid=(st+en)/2;
        if(arr[mid]>target) en=mid;
        else st=mid+1; // mid값과 target값이 일치하면 바로 빠져나옴
    }
    return st;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t;
        // 가장 오른쪽의 위치 - 가장 왼쪽의 위치
        cout<<upper_idx(t, n)-lower_idx(t, n)<<'\n';
        
        // STL 사용할 경우
        //cout<<upper_bound(arr, arr+n, t)-lower_bound(arr, arr+n, t)<<'\n';
    }
}