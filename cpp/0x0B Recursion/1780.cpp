#include <bits/stdc++.h>
using namespace std;

int N;
int matrix[2200][2200];
int cnt[3]; //-1, 0, 1로 채워진 종이 개수

bool check(int x, int y, int n){
    for(int i=x;i<x+n;i++)
    for(int j=y;j<y+n;j++)
        if(matrix[x][y]!=matrix[i][j])
            return false;
    return true;
}

void recursion(int x, int y, int z){
    if(check(x, y, z)){
        cnt[matrix[x][y]+1]+=1; //-1->cnt[0], 0->cnt[1], 1->cnt[2]로 저장
        return;
    }
    int n=z/3;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        recursion(x+i*n, y+j*n, n);
}

int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>matrix[i][j];
        }
    }
    recursion(0,0,N);
    for(int i=0;i<3;i++){
        cout<<cnt[i]<<"\n";
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}