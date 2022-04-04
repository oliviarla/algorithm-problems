#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

//남, 동, 북, 서 (시계반대방향)
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
//사무실 모양 저장
int board1[10][10];
//방문 표시
int board2[10][10];
//cctv 좌표 저장
vector<pair<int, int> > cctv;

bool OOB(int a, int b){
    return a<0||a>=n||b<0||b>=m;
}

void upd(int x, int y, int dir){
    dir %=4; //4진법 수행 가능하도록 함
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(OOB(x, y)||board2[x][y]==6) return;
        if(board2[x][y]!=0) continue;
        board2[x][y]=7;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    int mn = 0; //빈칸 개수 저장

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board1[i][j];
            if(board1[i][j]!=0&&board1[i][j]!=6)
                cctv.push_back({i, j});
            if(board1[i][j]==0) mn++;
        }
    }

    for(int tmp=0;tmp<(1<<(2*cctv.size())); tmp++){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                board2[i][j]=board1[i][j]; //원본 값 board2에 복사
        int brute = tmp;

        for(int i=0;i<cctv.size();i++){ // 카메라가 있는 좌표마다 board2 개선
            int dir=brute%4;
            brute /=4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            if(board1[x][y]==1){ //1번 카메라
                upd(x, y, dir);
            }
            else if (board1[x][y]==2){ //2번 카메라
                upd(x, y, dir);
                upd(x, y, dir+2);
            }
            else if (board1[x][y]==3){ //3번 카메라
                upd(x, y, dir);
                upd(x, y, dir+1);
            }
            else if (board1[x][y]==4){ //4번 카메라
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
            }
            else if (board1[x][y]==5){ //5번 카메라
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
                upd(x, y, dir+3);
            }
        }
        int val =0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                val += (board2[i][j]==0);
            mn = min(mn, val); //빈칸 개수 갱신
    }
    cout<<mn;
}