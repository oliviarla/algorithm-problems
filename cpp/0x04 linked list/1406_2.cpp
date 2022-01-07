#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char data){
    //unused 칸에 추가
    dat[unused] = data;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr]!=-1) //addr이 마지막 원소가 아닐 경우
        pre[nxt[addr]]=unused; //원래 addr 다음 원소의 pre값 변경
    nxt[addr]=unused; //addr의 다음 원소로 현재 원소를 지정
    unused++;
}

void erase(int addr){
    //간단 구현이므로 unused는 복구하지 않음
    nxt[pre[addr]]=nxt[addr];
    if(nxt[addr]!=-1)
        pre[nxt[addr]]=pre[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //list 구현체 사용

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string init;
    cin>>init;
    
    //원소 입력
    int cursor = 0;
    for(auto c:init) {
        insert(cursor, c);
        cursor++;
    }
    traverse();
    int q;
    cin>>q;

    while (q--){
        char op;
        cin>>op;
        if (op=='P'){
            char add;
            cin>>add;
            insert(cursor, add);
            cursor = nxt[cursor];
        }
        else if (op=='L'){ 
            if (pre[cursor]!=-1) cursor = pre[cursor];
        }
        else if (op=='D'){
            if(nxt[cursor]!=-1) cursor=nxt[cursor];
        }
        else {
            if(cursor!=0){
                erase(cursor);
                cursor=pre[cursor];
            }
        }
    }
    traverse();
}