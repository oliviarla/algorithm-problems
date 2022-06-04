#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        unordered_map<string, int> um;
        int n, ans=1;
        cin>>n;

        while(n--){
            string name, type;
            cin>>name>>type;
            um[type]++;
        }

        int result = 1;
        for(auto e: um){
            result *= e.second+1;
        }
        cout<<result-1<<'\n';
    }
}