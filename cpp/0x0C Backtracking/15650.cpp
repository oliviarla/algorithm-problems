#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

// 1~N까지 자연수 중 중복 없이 M개 고른 수열
// 오름차순
//백트래킹을 이용한 풀이
void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    int start = 1;
    if(k!=0) start=arr[k-1]+1; //수열에 이미 수가 존재할 경우 이전 수보다 1큰값을 시작값으로 잡기
    for(int i=start;i<=n;i++){ //시작하는 수를 기존 수열의 수보다 큰 값으로 잡음
        if(!isused[i]){
            isused[i]=1;
            arr[k]=i;
            func(k+1);
            isused[i]=0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    func(0);
}