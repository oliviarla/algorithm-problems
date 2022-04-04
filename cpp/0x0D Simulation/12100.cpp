#include <bits/stdc++.h>
using namespace std;

int n;
int board1[21][21];
int board2[21][21];

void rotate(){ // 90도 회전하여 기울이는 방향을 조정
    int tmp[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j]=board2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board2[i][j]=tmp[n-j-1][i];
        }
    }
}

void tilt(int dir){ //왼쪽으로 기울이는 함수
    while(dir--) rotate();
    for(int i=0;i<n;i++){
        int tilted[21]={};
        int idx =0;
        for(int j=0;j<n;j++){ //한 행마다 기울이기 진행
            if(board2[i][j]==0)
                continue;
            if(tilted[idx]==0)
                tilted[idx]=board2[i][j];
            else if(tilted[idx]==board2[i][j])
                tilted[idx++]*=2;
            else
                tilted[++idx]=board2[i][j];
        }
        for(int j=0;j<n;j++) board2[i][j] = tilted[j];
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>board1[i][j];
            }
        }
    int mx = 0;
    for(int t=0;t<1024;t++){ //5번의 기울이기 방향 경우의수 모두 체크
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board2[i][j]=board1[i][j];
            }
        }
        int brute =t;
        for(int i=0;i<5;i++){ //5진법을 사용해 방향 정보 얻기
            int dir = brute %4;
            brute /=4;
            tilt(dir);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mx = max(mx, board2[i][j]); //최댓값 찾기
            }
        }
    }
    cout<<mx;
}