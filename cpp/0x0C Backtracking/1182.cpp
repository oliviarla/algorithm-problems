#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[21];
int cnt=0;
bool isused[21];
//모든 부분집합을 구해 합을 계산하여 s와 일치하는지 검증

void func(int k, int total){
    if(k==n){
        if(total==s){
            cnt++;
        }
        return;
    }
    func(k+1, total); //현재값 부분수열에 미포함
    func(k+1, total+arr[k]); //현재값 부분수열에 포함
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    func(0, 0);
    if(s==0) cnt--; //크기가 양수인 부분집합이 아닌(공집합) 경우 제외
    cout<<cnt;
}