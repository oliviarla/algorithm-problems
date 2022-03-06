#include <bits/stdc++.h>
using namespace std;

int n,m;
int origin[10];
int arr[10];

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(origin[i]>=arr[k-1]){
            arr[k]=origin[i];
            func(k+1);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>origin[i];
    sort(origin, origin+n); //증가하는 순서로 출력하기 위해 정렬
    func(0);
}