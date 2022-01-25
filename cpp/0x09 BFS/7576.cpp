#include <bits/stdc++.h>
using namespace std;


int board[1001][1001];
int vis[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void){
    int n,m;
    cin>>m>>n;
    queue<pair<int, int> > Q;

    //vis -1로 전부 채우기
    fill(vis[0], vis[1000],-1);
    
    // 입력받은 값 저장
    //1: 익음
    //0: 익지 않음
    //-1: 토마토 없음
    bool isPerfect=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if (board[i][j]==1) {
                Q.push({i,j});
                vis[i][j]=0;
            }
            else if (board[i][j]==0) isPerfect=false;
            else if (board[i][j]==-1) vis[i][j]=-2;
        }
    }

    if(isPerfect){
        cout<<0; //저장될때부터 모두 익어있으면 0 출력
        exit(0);
    }
    int date;
    while(!Q.empty()){ 
        //익은 토마토의 좌표값을 가져옴
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(board[nx][ny]==1||board[nx][ny]==-1) continue;
            if(vis[nx][ny]!=-1) continue;
            vis[nx][ny]=vis[cur.first][cur.second]+1;
            date = vis[nx][ny]; //가장 마지막에 갱신되는 값 저장될 것
            Q.push({nx, ny});
        }
    }
    //모두 익을 수 있으면, 최소 날짜 출력
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (vis[i][j]==-1){
                cout<<-1<<'\n'; //모두 익지 못하면 -1 출력
                exit(0);
            }
        }
    }
    cout<<date<<'\n';
}