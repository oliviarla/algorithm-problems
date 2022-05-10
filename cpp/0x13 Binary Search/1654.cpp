#include <bits/stdc++.h>
using namespace std;

// N개를 만들 수 있는 랜선의 최대 길이? (최적화 문제)
// 랜선의 길이가 X일 때 랜선이 N개 이상인가 아닌가? (결정 문제)

// 랜선의 길이가 작을수록 랜선의 개수가 커짐

typedef long long ll;
int k, n;
int arr[10005];

bool solve(ll x){
  ll cur = 0;
  for(int i = 0; i < k; i++) cur += arr[i] / x;
  return cur >= n; //n개 이상 랜선 생성 가능한지 여부를 반환
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k >> n;
  for(int i = 0; i < k; i++) cin >> arr[i];

  ll st = 1;
  ll en = 0x7fffffff; // 2^31 - 1
  while(st < en){
    ll mid = (st+en+1)/2; //1을 더해 무한루프 방지!
    if(solve(mid)) st = mid; //n개 이상 랜선 생성 가능시 가장 큰 n값을 구하기 위해 mid값 이동
    else en = mid-1;//n개 이상 랜선 생성 불가능 시 더 작은 범위에서 n값을 구하기 위해 mid값 이동
  }
  cout << st;
}