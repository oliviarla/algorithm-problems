#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int> > house;
    vector<pair<int, int> > chicken;
    int n,m;

    cin>>n>>m;
    int k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>k;
            if(k==1)
                house.push_back({i, j});
            else if(k==2)
                chicken.push_back({i, j});
        }
    }
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin()+chicken.size()-m, 0);

    int min_dist=INT_MAX;
    do{
        int dist =0;
        for(auto h:house){
            int tmp=INT_MAX;
            for(int i=0;i<chicken.size();i++){
                if(brute[i]==0) continue;
                // 1일 경우 조합의 원소임
                tmp = min(tmp, abs(chicken[i].X-h.X)+abs(chicken[i].Y-h.Y)); //최소 치킨거리 계산
            }
            dist += tmp; //총 치킨 거리에 각각의 치킨 거리 추가
        }
        min_dist = min(min_dist, dist); //총 치킨 거리가 줄어들었다면 갱신
    }while(next_permutation(brute.begin(), brute.end()));
    cout<<min_dist;
}