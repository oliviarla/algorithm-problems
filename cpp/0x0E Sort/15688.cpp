#include <bits/stdc++.h>
using namespace std;

int freq[2000001]={};
#define base 1000000

int main(void){
    //아래 두줄 안넣으면 시간초과남
    ios::sync_with_stdio(0);
    cin.tie(0);

    //counting sort
    int n, tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        freq[tmp+base]++;
    }
    for(int i=0;i<2000001;i++){
        for(int j=0;j<freq[i];j++){
            cout<<i-base<<"\n";
        }
    }
}