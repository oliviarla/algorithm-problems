#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    queue<int> q;
    string op;
    for(int i=0;i<n;i++){
        cin>>op;
        if (op=="push"){
            int e;
            cin>>e;
            q.push(e);
        }
        else if(op=="front"){
            if (!q.empty()) cout<<q.front()<<'\n';
            else cout<<-1<<'\n';
        }
        else if(op=="back"){
            if (!q.empty()) cout<<q.back()<<'\n';
            else cout<<-1<<'\n';
        }
        else if(op=="size"){
            cout<<q.size()<<'\n';
        }
        else if(op=="pop"){
            if (!q.empty()){
                int p = q.front();
                q.pop();
                cout<<p<<'\n';
            }
            else cout<<-1<<'\n';
        }
        else if(op=="empty"){
            if(q.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}