#include <bits/stdc++.h>
using namespace std;

int main(void){
    list<char> l;
    auto cur = l.end();
    l.insert(cur, 'a');
    for(auto c:l){
        cout<<c;
    }
}