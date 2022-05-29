#include <bits/stdc++.h>
using namespace std;

int count(vector<string> v, string s){
    return upper_bound(v.begin(), v.end(), s)
        -lower_bound(v.begin(), v.end(), s);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> enter;
    vector<string> leave;
    vector<string> result;

    int logs;
    cin>>logs;
    while(logs--){
        string name, status;
        cin>>name>>status;
        if(status=="enter") enter.push_back(name);
        else leave.push_back(name);
    }
    sort(enter.begin(), enter.end());
    sort(leave.begin(), leave.end());
    
    string now = "";
    for(auto e: enter){
        if(now != e) now = e;
        int enter_idx = count(enter, now);
        int leave_idx = count(leave, now);
        if(enter_idx>leave_idx) result.push_back(now);
    }
    reverse(result.begin(), result.end());
    for(auto e:result) cout<<e<<'\n';
}