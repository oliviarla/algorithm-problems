#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int set[10]={0,};
    cin>>N;

    while(N!=0){
        set[N%10]++;
        N/=10;
    }

    //직접 구현한 것

    //6, 9번째 인덱스를 제외한 최댓값 구함
    int max = *max_element(set, set+6);
    if (max<*max_element(set+7, set+9))
        max = *max_element(set+7, set+9);

    //6, 9번째 인덱스와 비교
    if (max>ceil((set[6]+set[9])/2.0))
        cout<<max<<'\n';
    else
        cout<<ceil((set[6]+set[9])/2.0)<<'\n';

    //정답 코드

    int ans = 1; //N=0일때에 대한 예외 처리 가능

    //6, 9번째 인덱스를 제외한 최댓값 구함
    for(int i=0;i<10;i++){
        if (i==6||i==9) continue;
        ans = max(ans, a[i])
    }
    
    //6, 9번째 인덱스와 비교
    ans = max(ans, (a[6]+a[9]+1)/2); // ceil 함수 대신 1을 더해 올림 처리
    cout <<ans;
    return 0;
}