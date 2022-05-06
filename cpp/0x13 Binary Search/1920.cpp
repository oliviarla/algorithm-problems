#include <bits/stdc++.h>
using namespace std;
int n, arr[100005], m, x;

int binary_search(int x){
    int st=0;
    int en=n-1;
    while(st<=en){
        int mid=(st+en)/2;
        
        if(arr[mid]<x){
            st=mid+1;
        }
        else if(arr[mid]>x){
            en=mid-1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);

    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>x;
        cout<<binary_search(x)<<'\n';
    }
}