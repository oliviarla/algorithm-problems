#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100001];
int n;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n); //정렬으로 같은 수를 인접하게 둠

    int cnt=0, mxcnt=0;
    ll mxval=-(1ll<<62); // 1을 long long으로 형변환하지 않고 1 << 62로 작성시 int overflow 발생

    for(int i=0;i<n;i++){
        if(i==0||arr[i-1]==arr[i]) cnt++;
        else{
            if(cnt>mxcnt){
                mxval=arr[i-1];
                mxcnt=cnt;
            }
            cnt=1;
        }
    }
    if(cnt>mxcnt) mxval=arr[n-1]; //가장 마지막 원소 처리 필요
    cout<<mxval;
}