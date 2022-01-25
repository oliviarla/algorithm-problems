#include <bits/stdc++.h>
using namespace std;

//1. 시작하는 칸을 큐에 넣고 방문 표시
//2. 큐에서 원소 꺼내 상하좌우 방문 확인
//3. 방문했다면 방문 표시하고 좌표 큐에 삽입
//4. 큐가 빌 때까지 2~3 반복
// 모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 n개이면 O(n)

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    int n,m; //세로, 가로 입력
    cin>>n>>m;
    queue<pair<int, int> > Q;
    
    //입력받은 값 board에 저장
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>board[i][j];
    }
    int max_width = 0;
    int iter=0;
    int width=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (!vis[i][j]&&board[i][j]!=0){
                Q.push({i,j});
                vis[i][j]=1;
                width = 0;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    width++;
                    //cout<<cur.first<<" "<<cur.second<<'\n';
                    for(int k=0;k<4;k++){
                        int nx = cur.first+dx[k];
                        int ny = cur.second+dy[k];
                        if (nx<0||ny<0||nx>=n||ny>=m) continue;
                        if(vis[nx][ny]||board[nx][ny]!=1) continue;
                        vis[nx][ny]=1;
                        Q.push({nx, ny});
                    }
                }
                if (max_width<width) max_width=width;
                iter++;
            }
        }
    }
    cout<<iter<<'\n';
    cout<<max_width<<'\n';
}