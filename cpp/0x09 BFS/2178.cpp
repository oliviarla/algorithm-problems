#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[101][101];
int vis[101][101];
int main(void){    
    queue<pair<int, int> > Q;
    fill(vis[0], vis[100], -1);
    int n,m;
    cin>>n>>m;
    // 입력받은 값 board에 저장
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int j= 0;
        for(char e:s){
            board[i][j]=e-'0';
            j++;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //         cout<<vis[i][j];
    //     cout<<'\n';
    // }

    // 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어짐
    // 즉 처음 위치부터 상하좌우 탐색만 하면 되는 것
    Q.push({0,0});
    vis[0][0]=1; //vis 배열에 처음 위치로부터의 거리를 저장함
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();        
        for(int dir=0;dir<4;dir++){
            int nx = cur.first +dx[dir];
            int ny = cur.second+dy[dir];

            if (nx<0||ny<0||nx>=n||ny>=m) continue;
            if(vis[nx][ny]!=-1 || board[nx][ny]!=1) continue;
            vis[nx][ny]=vis[cur.first][cur.second]+1;
            Q.push({nx, ny});
        }
        
    }

    cout<<vis[n-1][m-1];

}