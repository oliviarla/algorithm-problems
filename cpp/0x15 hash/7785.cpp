#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;

    while(n--){
        string name, status;
        cin>>name>>status;
        if(status=="enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> res(s.begin(), s.end());
    sort(res.begin(), res.end(), greater<string> ());
    for(auto e: res){
        cout<<e<<'\n';
    }
}