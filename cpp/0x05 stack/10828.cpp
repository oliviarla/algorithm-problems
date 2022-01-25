#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;

    int n;
    cin>>n;
    string op;
    for(int i=0;i<n;i++){
        cin>>op;
        if (op=="push"){
            int e;
            cin>>e;
            s.push(e);
        }
        else if(op=="top"){
            if(!s.empty())
                cout<<s.top()<<'\n';
            else cout<<-1<<'\n';
        }
        else if(op=="size"){
            cout<<s.size()<<'\n';
        }
        else if(op=="pop"){
            if (!s.empty()){
                int pop = s.top();
                s.pop();
                cout<<pop<<'\n';
            }
            else cout<<-1<<'\n';
            
        }
        else if(op=="empty"){
            if(s.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}