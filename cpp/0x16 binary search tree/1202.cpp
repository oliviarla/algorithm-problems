#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int, int> jewel[300005];
multiset<int> bag;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k; //보석 개수, 가방 개수
    cin>>n>>k;
    int w, v;
    for(int i=0;i<n;i++){
        cin>>w>>v; //무게, 가치
        jewel[i]={v, w}; //정렬을 위해 가치부터 저장
    }
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        bag.insert(c);
    }

    sort(jewel, jewel+n);

    long long res = 0;

    for(int i=n-1;i>=0;i--){
        auto itr = bag.lower_bound(jewel[i].Y);
        if(itr!=bag.end()){
            res += jewel[i].X;
            bag.erase(itr);
        }
    }
    cout<<res;
}