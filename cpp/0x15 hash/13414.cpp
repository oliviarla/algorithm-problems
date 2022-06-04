#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

#define X first
#define Y second

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, l;
    cin>>k>>l;
    
    for(int idx=0;idx<l;idx++){
        string id;
        cin>>id;
        if(m.find(id)!=m.end()) m.erase(id);
        m[id]=idx;
    }

    vector<pair<string, int> > v(m.begin(), m.end());


    sort(v.begin(), v.end(), [](auto& a, auto& b) {return a.Y<b.Y;});
    
    int en = min(k, (int)v.size());
    for(int i=0;i<en;i++){
        cout<<v[i].X<<'\n';
    }
}