#include <bits/stdc++.h>
using namespace std;


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void){
    int T;
    cin>>T;
    //각 테스트케이스 별로 입력 받음
    while(T--){
        int m, n, k;
        cin>>m>>n>>k; //가로, 세로 길이 입력받기
        int matrix[51][51]={0,};
        int vis[51][51]={0,};
        int x,y;
        
        for(int i=0;i<k;i++){
            cin>>x>>y;
            matrix[x][y]=1; //배추 위치 저장
        }
        
        int total=0; //인접한 배추 그룹의 총 개수
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                queue<pair<int, int> > Q;
                if(matrix[i][j]==1&&vis[i][j]!=1){
                    //배추 존재 and 방문기록 없으면
                    vis[i][j]=1; //방문 처리(!!!)
                    Q.push({i, j});
                    while(!Q.empty()){
                        auto cur = Q.front();
                        Q.pop();
                        for(int dir=0;dir<4;dir++){ //상하좌우 체크
                            int nx = cur.first+dx[dir];
                            int ny = cur.second+dy[dir];
                            if(nx<0||nx>=m||ny<0||ny>=n) continue;
                            if (matrix[nx][ny]==1&&vis[nx][ny]!=1){
                                vis[nx][ny]=1;
                                Q.push({nx, ny});
                                
                            }
                        }
                    }
                    total ++;
                }
            }
        }
        cout<<total<<"\n";
    }
    
}