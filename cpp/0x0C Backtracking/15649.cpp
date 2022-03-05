
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

//백트래킹 사용한 버전

void func(int k){ //k개만큼의 수를 택했다는 뜻
    if(k==m){ // 최대값 m에 도달하면 함수 종료
        // arr 출력
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        return;
    }
    for(int i=1;i<=n;i++){ //1부터 n까지 돌면서 사용된 수인지 확인
        if(!isused[i]){
            arr[k]=i; //k번째 수가 i라고 저장
            isused[i]=1; //i라는 수가 사용되었다고 저장
            func(k+1);
            isused[i]=0;//i라는 수를 사용하지 않음을 저장
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}