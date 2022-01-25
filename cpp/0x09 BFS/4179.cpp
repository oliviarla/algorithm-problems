#include <bits/stdc++.h>
using namespace std;

string board[1001];
int dist_fire[1001][1001];
int dist_jihoon[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R, C;
    cin>>R>>C;
    // 미로 정보 입력
    for(int i=0;i<R;i++){
        cin>>board[i];
    }

    
    
    // 시간 정보 저장하는 배열의 기본값을 -1로 설정
    for(int i=0;i<R;i++){
        fill(dist_fire[i], dist_fire[i]+C, -1);
        fill(dist_jihoon[i], dist_jihoon[i]+C, -1);
    }

    // 불의 시작점, 지훈의 시작점 큐에 입력
    queue<pair<int, int> > Q_fire, Q_jihoon;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j]=='F'){
                Q_fire.push({i,j});
                dist_fire[i][j]=0;
            }
            else if(board[i][j]=='J'){
                Q_jihoon.push({i, j});
                dist_jihoon[i][j]=0;
            }
        }
    }

    //불에 대한 BFS
    while(!Q_fire.empty()){
        pair<int, int> cur = Q_fire.front();
        Q_fire.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0 || ny<0 || nx>=R || ny>=C) //범위 벗어날 경우 측정x
                continue;
            if(dist_fire[nx][ny]>=0 || board[nx][ny]=='#') //이미 측정되었거나 벽이면 측정x
                continue;
            dist_fire[nx][ny]=dist_fire[cur.first][cur.second]+1;
            Q_fire.push({nx, ny});
        }
    }

    //지훈에 대한 BFS 진행하는 동시에 탈출 여부 체크
    while(!Q_jihoon.empty()){
        pair<int, int> cur = Q_jihoon.front();
        Q_jihoon.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];

            if(nx<0 || ny<0 || nx>=R || ny>=C){
                //범위를 벗어나면 탈출한 것
                cout<<dist_jihoon[cur.first][cur.second]+1;
                return 0;
            }
            if(dist_jihoon[nx][ny]>=0 || board[nx][ny]=='#') //이미 측정됐거나 벽이면 측정x
                continue;
            
            // 불이 먼저 전파되었으면 이동 불가
            if(dist_fire[nx][ny]!=-1 && dist_jihoon[cur.first][cur.second]+1>=dist_fire[nx][ny]) 
                continue;
            
            //모든 조건을 통과했으면 한칸 이동
            dist_jihoon[nx][ny]=dist_jihoon[cur.first][cur.second]+1;
            Q_jihoon.push({nx, ny});
        }
    }

    cout<<"IMPOSSIBLE";
}
