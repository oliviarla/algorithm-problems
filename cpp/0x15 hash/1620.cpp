#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> str_to_int; //{Bulbasaur, 1}
string int_to_str[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>> int_to_str[i];
        str_to_int[int_to_str[i]]=i;
    }

    while(m--){
        string s;
        cin>>s;
        if(isalpha(s[0])) cout<<str_to_int[s]<<'\n';
        else cout<<int_to_str[stoi(s)]<<'\n';
    }
}