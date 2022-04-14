#include <bits/stdc++.h>
using namespace std;

string board[4];

void clockwise(int n){
    int temp = board[n][7];
    for(int i=6;i>=0;i--){
        board[n][i+1]=board[n][i];
    }
    board[n][0]=temp;
}

void anticlockwise(int n){
    int temp = board[n][0];
    for(int i=1;i<8;i++){
        board[n][i-1]=board[n][i];
    }
    board[n][7]=temp;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<4;i++){
        cin>>board[i];
    }
    
    vector<pair<int, int> > V;
    int rotate_cnt;

    cin>>rotate_cnt;
    int x, dir;
    for(int i=0;i<rotate_cnt;i++){
        cin>>x>>dir;
        int dirs[4]={};
        dirs[x-1]=dir;
        // x의 왼쪽으로 회전 전파
        int idx=x-1;
        while(idx>0&&board[idx-1][2]!=board[idx][6]){
            dirs[idx-1]= -dirs[idx];
            idx--;
        }
        idx =x-1;
        //x의 오른쪽으로 회전 전파
        while(idx<3&&board[idx][2]!=board[idx+1][6]){
            dirs[idx+1]=-dirs[idx];
            idx++;
        }
        
        for(int i=0;i<4;i++){
            if(dirs[i]==1){
                clockwise(i);
            }
            else if (dirs[i]==-1){
                anticlockwise(i);
            }
        }
    }

    int score=0;
    for(int i=0;i<4;i++){
        if(board[i][0]=='1'){
            score+=(1<<i);
        }
    }
    cout<<score<<"\n";
}