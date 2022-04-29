#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,k, arr[10];
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];

    int coins=0;
    for(int i=n-1;i>=0;i--){
        if(k/arr[i]>0){
            coins+=k/arr[i];
            k%=arr[i];
        }
    }
    cout<<coins;

}