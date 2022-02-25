#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c){
    if(n==0) return 0; //base condition
    
    int half = pow(2, n-1);
    if(r<half && c<half){ //0부터 시작하므로 범위 조건 주의할 것
        //1번 사각형
        return func(n-1, r, c);
    }
    if (r<half && c>=half){
        //2번 사각형
        return half*half+func(n-1, r, c-half);
    }
    if(r>=half &&c<half){
        //3번 사각형
        return 2*half*half+func(n-1, r-half, c);
    }
    //4번 사각형
    return 3*half*half+func(n-1, r-half, c-half);    
}

int main(void){
    int n, r, c;
    cin>>n>>r>>c;

    cout<<func(n, r, c);
}