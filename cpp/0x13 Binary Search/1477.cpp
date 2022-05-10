#include <bits/stdc++.h>
using namespace std;

int N, M, L;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>L;
    vector<int> store;
    int pos;
    for(int i=1;i<=N;i++) {
        cin>>pos;
        store.push_back(pos);
    }
    store.push_back(L);
    sort(store.begin(), store.end());

    int left = 1;
    int right = L-1;
    int mid=0;
    // 1 ~ L-1 중 새로 세울 휴게소 간의 거리를 이분탐색으로 구해본다 
    while(left <= right){
        mid=(left+right)/2;
        int new_store=0;
        for(int i=0;i<store.size();i++){
            int dist = store[i]-store[i-1]; // 각 휴게소간의 간격 저장

            //휴게소 간의 간격을 새로 세울 휴게소 간의 거리로 나누어 몇개의 휴게소 세울 수 있는지 저장
            new_store += (dist/mid); 
            if(dist%mid ==0) new_store--; //값이 나누어 떨어지는 경우 겹치는 휴게소 제거
        }
        if(new_store>M){ //만약 M개 이상으로 휴게소가 생겼다면
            //휴게소 간 거리 늘림
            left = mid+1;
        }
        else{
            //휴게소 간 거리 줄임
            right = mid-1;
        }
    }
    cout<<left;
}