#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //list stl 사용

    string init;
    cin>>init;

    list<char> L;
    for(auto c:init) L.push_back(c);

    auto cursor = L.end(); //커서를 문장의 맨 뒤에 위치시킴

    int q;
    cin>>q;

    while (q--){
        char op;
        cin>>op;
        if (op=='P'){
            char add;
            cin>>add;
            L.insert(cursor, add);
        }
        else if (op=='L'){ 
            if (cursor!=L.begin()) cursor--;
        }
        else if (op=='D'){
            if(cursor!=L.end()) cursor++;
        }
        else {
            if(cursor!=L.begin()){
                cursor--;
                cursor = L.erase(cursor); //틀린 이유!
                //erase 후 커서 위치를 동일하게 유지하려면 대입 필요
            }
        }
    }
    for(auto c:L) cout<<c;
}