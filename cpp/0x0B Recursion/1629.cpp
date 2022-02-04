#include <bits/stdc++.h>
using namespace std;
/*
* 예제
//거듭제곱의 나머지 구하는 함수
int func1(int a, int b, int m){
    int val=1;
    while(b--) val *=a; // -> int overflow 발생 가능
    return val%m;
}

//개선된 함수
using ll = long long;
ll func1(ll a, ll b, ll m){
    ll val=1;
    while(b--) val = val*a%m; //나머지 값만 저장해 overflow 방지
    return val;
}

*/

// k승을 계산하면 2k승과 2k+1승을 계산할 수 있음

// 1) a^n * a^n = a^2n 성질 활용
// 2) 12^58 mod 67 =4 이면
//    12^116 mod 67 == 4*4 mod 67 임


using ll=long long;
ll func(ll a, ll b, ll c){
    if (b==1)
        return a%c;
    ll res = func(a, b/2, c); //k일 때를 계산
    res = res*res%c;
    if (b%2==0) return res; //2k 일 경우를 계산
    return res*a%c; //2k+1일 경우 2k에 a를 곱하여 계산
} 

int main(void){
    ll a, b, c;
    cin>>a>>b>>c;

    cout << func(a, b, c);

    //시간초과 나는 로직
    // while(b--){
    //     var = var* a%c;
    // }
    // cout<<var;
}