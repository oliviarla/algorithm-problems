#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int note[45][45];
int r,c;
int sticker[15][15];
bool pastable(int x, int y){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(note[x+i][y+j]==1 && sticker[i][j]==1)
                return false;
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(sticker[i][j]==1)
                note[x+i][y+j]=1;
    return true;
}

void rotate(){
    int temp[15][15];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            temp[i][j]=sticker[i][j];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            sticker[i][j]=temp[r-j-1][i];
        }
    }
    swap(r,c);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    
    while(k--){
        cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>sticker[i][j];
            }
        }
        for(int dir = 0; dir <4;dir++){
            bool is_paste=false;
            for(int i=0;i<=n-r;i++){
                if(is_paste) break;
                for(int j=0;j<=m-c;j++){
                    if(pastable(i,j)){
                        is_paste=true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate(); //(0, 0) ~ (n-r, m-c)까지 전부 불가능일 때 rotate
        }
        
    }
    

    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res+=note[i][j];
        }
    }
    cout<<res;
}