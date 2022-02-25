#include <bits/stdc++.h>
using namespace std;

// 원반 n개를 기둥 a에서 기둥 b로 옮기는 방법 출력하는 함수
void func(int a, int b, int n){
    if(n==1){
        cout<<a<<' '<<b<<'\n'; // a번째 탑 가장 위 원판 -> b번째 탑 가장 위 원판
        return;
    }
    // n-1개의 원판을 기둥 a -> 기둥 6-a-b로 옮김
    func(a, 6-a-b, n-1); //6-a-b : 비어있는 기둥의 번호 구함
    // n번 원판 기둥 a-> 기둥 b로 옮김
    cout<<a<<' '<<b<<'\n';
    // n-1개의 원판을 기둥 6-a-b -> 기둥 b로 옮김
    func(6-a-b, b, n-1);
}

int main(void){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<'\n';
    func(1, 3, n);
}