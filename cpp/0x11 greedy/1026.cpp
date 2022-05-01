#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
    return a>b;

}

int main(void){
    int n, a[51], b[51];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    
    sort(a, a+n);
    sort(b, b+n, comp);
    int ans=0;
    for(int i=0;i<n;i++) ans += a[i]*b[i];
    cout<<ans;
}