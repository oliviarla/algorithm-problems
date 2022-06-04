#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> um;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        string adr, pw;
        cin>>adr>>pw;
        um[adr]=pw;
    }
    
    for(int i=0;i<m;i++){
        string findadr;
        cin>>findadr;
        cout<<um[findadr]<<'\n';
    }
}