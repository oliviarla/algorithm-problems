#include <bits/stdc++.h>
using namespace std;

// 1~N까지 자연수 중 M개 고른 수열
// 중복 가능

int n, m;
int arr[10];
void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        arr[k]=i;
        func(k+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    func(0);
}