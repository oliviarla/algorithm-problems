#include <bits/stdc++.h>
using namespace std;

char picture[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;


void bfs(int i, int j)
{
    queue<pair<int, int> > Q;
    vis[i][j] = true;
    Q.push({i, j});
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n | ny < 0 || ny >= n)
                continue;
            if(vis[nx][ny]==true || picture[i][j]!=picture[nx][ny])
                continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int area(){
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            { //방문 안했을때
                bfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> picture[i][j];
        }
    }
    //RGB 구분될 경우
    int normal=area();

    // vis 배열 초기화
    for (int i = 0; i < n; i++)
    {
        fill(vis[i], vis[i] + n, false);
    }

    //R==G, B일 경우
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(picture[i][j]=='G')
                picture[i][j]='R'; //G값을 R으로 모두 변환
        }
    }
    int abnormal= area();
    
    cout << normal<<" "<<abnormal;
}