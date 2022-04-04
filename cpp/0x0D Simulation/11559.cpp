#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board1[13][7];
char board2[13][7];


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


// 하나라도 터지면 연쇄 +1
// 4개 이상 인접한 색 찾아 '.'으로 처리
bool pop_nearby(){
    bool visited[13][7]={};
    bool combo = false;
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            if(board1[i][j]=='.' || visited[i][j]) continue;
            queue<pair<int, int> > Q;
            queue<pair<int, int> > Store;
            char val = board1[i][j];
            int count= 1;
            Q.push({i, j});
            Store.push({i, j});
            visited[i][j]=1;

            while(!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                int x = cur.X, y = cur.Y;
                //cout<<x<<" "<<y<<"\n";
                for(int dir=0;dir<4;dir++){
                    int nx = x+dx[dir];
                    int ny = y+dy[dir];
                    if(nx<0||nx>13||ny<0||ny>13) continue;
                    if(board1[nx][ny]==val && !visited[nx][ny]){ //같은 색과 방문여부 체크
                        Q.push({nx, ny});
                        visited[nx][ny]=1;
                        Store.push({nx, ny});
                        count++;
                    }
                }
            }
            while(!Store.empty()){
                pair<int, int> now = Store.front();
                Store.pop();
                if(count>=4){ //4개이상 연속이면 삭제처리
                    if(!combo)
                        combo=1;
                    board1[now.X][now.Y]='.';
                }
            }
        }
    }
    return combo;
}

// 아래로 밀어서 이동시키는 함수
void down(){
    
    for(int i=0;i<6;i++){
        char pushed[13]={};
        fill(pushed, pushed+13, '.');
        int idx=11;
        for(int j=11;j>=0;j--){
            if(board1[j][i]!='.')
                pushed[idx--]=board1[j][i];
        }
        for(int j=11;j>=0;j--){
                board1[j][i]=pushed[j];
        }
    }
    
    
}



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int combos=0;

    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>>board1[i][j];
        }
    }

    while(pop_nearby()){ //연쇄가 일어나면
        combos++; //연쇄 값 증가
        down(); //아래로 이동시킴
    }

    if(combos)
        cout<<combos;
    else
        cout<<0;
}