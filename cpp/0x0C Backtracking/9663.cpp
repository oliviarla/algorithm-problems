#include <bits/stdc++.h>
using namespace std;

int n;
bool isused1[15]; // column(열) 체크
bool isused2[30]; // '/' 방향 대각선 체크
bool isused3[30]; // '\' 방향 대각선 체크

int cnt=0;

void func(int k){ //k는 행을 나타냄
    if(k==n){ //마지막 행까지 도달하면 cnt 추가
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        if(isused1[i]||isused2[i+k]||isused3[k-i+n-1])
            continue; // 같은 열, 대각선에 이미 존재할 경우 패스
        isused1[i]=1; 
        isused2[i+k]=1;
        isused3[k-i+n-1]=1;
        func(k+1);
        isused1[i]=0;
        isused2[i+k]=0;
        isused3[k-i+n-1]=0;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0);
    cout<<cnt;
}