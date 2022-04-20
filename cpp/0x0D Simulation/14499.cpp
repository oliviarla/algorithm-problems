#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,k;
int dir;
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};
int dice[7]={};
int matrix[21][21];

void rotate(int dir){
    int d1, d2, d3, d4, d5, d6;
    d1=dice[1], d2=dice[2], d3=dice[3];
    d4=dice[4], d5=dice[5], d6=dice[6];

    if(dir==1){
        dice[1]=d4;
        dice[4]=d6;
        dice[6]=d3;
        dice[3]=d1;
    }
    else if(dir==2){
        dice[4]=d1;
        dice[6]=d4;
        dice[3]=d6;
        dice[1]=d3;
    }
    else if(dir==3){
        dice[1]=d5;
        dice[2]=d1;
        dice[6]=d2;
        dice[5]=d6;
    }
    else if(dir==4){
        dice[5]=d1;
        dice[1]=d2;
        dice[2]=d6;
        dice[6]=d5;
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>x>>y>>k;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    while(k--){
        cin>>dir;
        
        int nx = dx[dir-1]+x;
        int ny = dy[dir-1]+y;
        //cout<<nx<<" "<<ny<<"\n";
        if(nx<0 || nx>=n || ny<0 || ny>=m)
            continue;
        rotate(dir);
        if(matrix[nx][ny]==0){
            matrix[nx][ny]=dice[6];
        }
        else {
            dice[6]=matrix[nx][ny];
            matrix[nx][ny]=0;
        }
        x=nx, y=ny;
        
        cout<<dice[1]<<"\n";
    }
}