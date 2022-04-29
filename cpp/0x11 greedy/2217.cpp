#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, arr[100001];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n); 
    int ans=0;
    for(int i=1;i<=n;i++)
        ans = max(ans, arr[n-i]*i);
    cout<<ans;
}