#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    deque<int> d;
    string op;
    for(int i=0;i<n;i++){
        cin>>op;
        if (op=="push_back"){
            int e;
            cin>>e;
            d.push_back(e);
        }
        else if (op=="push_front"){
            int e;
            cin>>e;
            d.push_front(e);
        }
        else if(op=="front"){
            if (!d.empty()) cout<<d.front()<<'\n';
            else cout<<-1<<'\n';
        }
        else if(op=="back"){
            if (!d.empty()) cout<<d.back()<<'\n';
            else cout<<-1<<'\n';
        }
        else if(op=="size"){
            cout<<d.size()<<'\n';
        }
        else if(op=="pop_front"){
            if (!d.empty()){
                int pf = d.front();
                d.pop_front();
                cout<<pf<<'\n';
            }
            else cout<<-1<<'\n';
        }
        else if(op=="pop_back"){
            if (!d.empty()){
                int pb = d.back();
                d.pop_back();
                cout<<pb<<'\n';
            }
            else cout<<-1<<'\n';
        }
        else if(op=="empty"){
            if(d.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}