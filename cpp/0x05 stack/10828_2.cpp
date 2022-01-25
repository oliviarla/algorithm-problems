#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos++]=x;
}

void pop(){
    pos--;
}

int top(){
    return dat[pos-1];
}

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    string op;
    for(int i=0;i<n;i++){
        cin>>op;
        if (op=="push"){
            int e;
            cin>>e;
            push(e);
        }
        else if(op=="top"){
            if(pos)
                cout<<top()<<'\n';
            else cout<<-1<<'\n';
        }
        else if(op=="size"){
            cout<<pos<<'\n';
        }
        else if(op=="pop"){
            if (pos){
                int p = top();
                pop();
                cout<<p<<'\n';
            }
            else cout<<-1<<'\n';
            
        }
        else if(op=="empty"){
            if(pos==0) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}