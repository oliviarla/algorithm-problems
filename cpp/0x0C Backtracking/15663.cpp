#include <bits/stdc++.h>
using namespace std;

int n,m;
int origin[10];
int arr[10];
int isused[10];

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    int tmp = 0;
    for(int i=0;i<n;i++){
        if(!isused[i]&& tmp != origin[i]){ //이전 수열의 마지막 항과 새로 추가할 값이 같지 않도록 해 중복 수열 막음
            isused[i]=1;
            arr[k]=origin[i];
            tmp = arr[k]; //재귀를 거치면서 마지막 수만 비교 가능
            //cout<<"tmp: "<<tmp<<"\n";
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