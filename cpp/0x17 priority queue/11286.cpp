#include <bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator() (int a, int b){ // priority queue는 반대로 정렬되므로 절댓값이 큰거부터 정렬하기
        if(abs(a)!=abs(b)) return abs(a)>abs(b); //앞 값이 뒤보다 크면 true
        else return a>0 && b<0; //두 절대값 같다면 앞의 값이 양수, 뒤의 값이 음수일 때 true
    }
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, cmp> pq;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x==0){
            if(!pq.empty()){ //절댓값 가장 작은 값 출력 후 제거
                int min = pq.top();
                cout<<min<<'\n';
                pq.pop();
            }
            else{
                cout<<0<<'\n'; //배열이 비어있을 경우 0 출력
            }
        }
        else{
            pq.push(x); //배열에 값 추가
        }
    }
}