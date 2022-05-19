#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    int arr[100005];

    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>arr[i];

    int min_len = 0x3f3f3f3f;

    int en = 0;
    int total = arr[0]; //total값을 새로 계산하지 않고 계속 갖고있는 것이 포인트
    for(int st=0;st<n;st++){
        while(total<s && en < n){
            en++;
            if(en!=n) total += arr[en];
        }
        if(en==n) break;
        min_len = min(min_len, en-st+1);
        total-=arr[st];
    }
    if(min_len==0x3f3f3f3f) cout<<0;
    else cout<<min_len;
}