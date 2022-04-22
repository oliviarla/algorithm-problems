#include <bits/stdc++.h>
using namespace std;

int n, house[1001][3];
int D[1001][3];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>house[i][j];
    
    D[0][0]=house[0][0];
    D[0][1]=house[0][1];
    D[0][2]=house[0][2];
    
    for(int i=1;i<n;i++){
        D[i][0]=min(D[i-1][1],D[i-1][2])+house[i][0];
        D[i][1]=min(D[i-1][0],D[i-1][2])+house[i][1];
        D[i][2]=min(D[i-1][0],D[i-1][1])+house[i][2];
    }

    cout<<min(min(D[n-1][0], D[n-1][1]), D[n-1][2]);

}