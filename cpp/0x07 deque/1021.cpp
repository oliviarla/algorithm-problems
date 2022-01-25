#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int n, m, total = 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
    
    for(int i=0;i<m;i++){
        int k, ans=0;
        cin>> k;
        // deque에서 k값의 위치 찾기
        int idx= find(dq.begin(), dq.end(), k)-dq.begin();
        while(dq.front()!=k){
            if (idx<dq.size()-idx){ //총 길이-idx와 idx값을 비교
                //idx값이 작으면 왼쪽으로 회전
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                //idx값이 크면 오른쪽으로 회전
                dq.push_front(dq.back());
                dq.pop_back();
            }
            total++;            
        }
        dq.pop_front();
    }
    //k번째 수를 뽑아내는데 드는 2,3번 연산의 최솟값 출력
    cout<<total;
}