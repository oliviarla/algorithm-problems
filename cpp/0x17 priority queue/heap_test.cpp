#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    heap[++sz]=x;
    int child = sz;
    while(child!=1){
        int parent = sz/2;
        if(heap[child]>=heap[parent]) break;
        swap(heap[child], heap[parent]);
        child = parent;
    }
}

int top(){
    return heap[1];
}

void pop(){
    int root = 1;
    heap[1]=heap[sz--]; //맨 마지막 원소를 루트로 이동시킴
    while(root*2 <= sz){ //왼쪽 자식의 인덱스가 sz보다 크다면 현재 노드는 리프
        int lc = root*2, rc = root*2+1; //왼쪽 자식, 오른쪽 자식
        int min_idx=lc; //오른쪽 자식 없을 수도 있으므로 왼쪽 자식부터 담음
        if(rc<=sz && heap[rc]<heap[lc]) min_idx=rc; //오른쪽 자식이 존재하고 왼쪽보다 작다면 최소인덱스 갱신
        if(heap[root]<=heap[min_idx]) break;
        swap(heap[root], heap[min_idx]);
        root = min_idx;
    }
    
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout<<heap[1]<<heap[2]<<heap[3]<<heap[4]<<'\n';
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}