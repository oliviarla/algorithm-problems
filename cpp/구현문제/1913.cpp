#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int x =0, y=0, num = n*n;
    int dx[4] ={0, 1, 0, -1};
    int dy[4] ={1, 0, -1, 0};

    int dir= 0;
    while(num>0){
        board[x][y]=num;        
        if(x+dx[dir]<0||y+dy[dir]<0||x+dx[dir]>=n||y+dy[dir]>=n||board[x+dx[dir]][y+dy[dir]]!=0)
            dir = (dir +1) %4;
        x = x+dx[dir];
        y = y+dy[dir];
        num --;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
}