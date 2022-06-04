#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin>>n;
    
    while(n--){
        int cards;
        cin>>cards;
        pq.push(cards);
    }

    int result = 0;
    while(pq.size()>1){
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        result += first+second;
        pq.push(first+second);
    }
    cout<<result;
}