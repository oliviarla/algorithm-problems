#include <bits/stdc++.h>
using namespace std;

int main(){
    int num[10]={0,};
    int a, b, c;
    cin>>a>>b>>c;
    int total = a*b*c;

    while(total!=0){
        num[total%10]++; // 1의자리 수를 계산해 배열 값 추가
        total/=10; // 자릿수 하나 줄임
    }

    for(int e:num)
        cout<<e<<'\n';
    return 0;
}