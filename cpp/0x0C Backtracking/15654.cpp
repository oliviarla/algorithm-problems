#include <bits/stdc++.h>
using namespace std;

// 주어진 수들에서
// 길이가 m인 수열 모두 구하기
//중복 없음

int n,m;
int origin[10];
int arr[10];
bool isused[10];

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(!isused[i]){
            arr[k]=origin[i];
            isused[i]=1;
            func(k+1);
            isused[i]=0;
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