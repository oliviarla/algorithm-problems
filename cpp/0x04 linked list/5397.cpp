#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        list<char> l;
        string s;
        cin>>s;
        auto cursor = l.begin();
        for (auto op:s){
            if (op=='<') {//커서 왼쪽으로 이동
                if (cursor!=l.begin()) cursor--;
            }
            else if(op=='>') {// 커서 오른쪽으로 이동
                if (cursor!=l.end()) cursor++;
            }
            else if (op=='-'){ //백스페이스
                if (cursor != l.begin()){
                    cursor--;
                    cursor=l.erase(cursor); //현재 커서의 문자 삭제
                }                
            }
            else{ //알파벳 들어오면
                l.insert(cursor, op); //현재 커서 자리에 새로 추가
            }
        }

        // 출력
        for (auto e:l) cout<<e;
        cout<<'\n';
    }
}