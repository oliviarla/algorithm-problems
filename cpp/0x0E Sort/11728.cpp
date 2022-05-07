#include <bits/stdc++.h>
using namespace std;

int A[10000001], B[10000001], AB[20000001];
int n,m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<m;i++)
        cin>>B[i];
    int idx_a=0, idx_b=0, idx_ab=0;
    while(idx_a<n || idx_b<m){
        if(idx_a>=n){
            while(idx_b<m)
                AB[idx_ab++]=B[idx_b++];
        }
        if(idx_b>=m){
            while(idx_a<n)
                AB[idx_ab++]=A[idx_a++];
        }
        if(A[idx_a]>B[idx_b]){
            AB[idx_ab++]=B[idx_b++];
        }
        else{
            AB[idx_ab++]=A[idx_a++];
        }
    }

    // 해답 코드

    // for(int i=0;i<n+m;i++){ //n+m만큼 돌면서
    //     if(idx_b==m) AB[i]=A[idx_a++]; //B 원소가 더이상 없으면 A원소 추가
    //     else if(idx_a==n) AB[i]=B[idx_b++]; //A 원소가 더이상 없으면 B원소 추가
    //     else if(A[idx_a]<=B[idx_b]) AB[i]=A[idx_a++]; //A원소 <= B원소 이면 A원소 추가 
    //     else AB[i]=B[idx_b++]; //A원소 > B원소 이면 B원소 추가
    // }

    for(int i=0;i<n+m;i++){
        cout<<AB[i]<<" ";
    }
}