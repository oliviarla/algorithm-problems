#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

//next_permutation 사용한 버전
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    do{
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        reverse(arr.begin()+m, arr.end()); 
        //nPn 대신 nPr을 만들기 위해 m개 이후의 값들 reverse해주어
        //m까지 순열의 중복을 막아 다음 순열로 넘어가도록 함
    }while(next_permutation(arr.begin(), arr.end()));
}