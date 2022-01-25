#include <bits/stdc++.h>
using namespace std;

int main(void){
    int K, num, total=0;
    cin>>K;
    stack<int> s;

    for(int i=0;i<K;i++){
        cin>>num;
        if (num){
            s.push(num);
        }
        else{
            s.pop();
        }
    }

    while(!s.empty()){
        total+=s.top();
        s.pop();
    }
    cout<<total;
}