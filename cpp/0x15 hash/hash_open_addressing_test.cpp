#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int EMPTY = -1; //비어있는 상태를 나타냄
const int OCCUPY = 0; //칸에 값이 들어있는 상태를 나타냄
const int DUMMY = 1; //칸에 값이 있었다 제거된 상태를 나타냄
int status[M]; // EMPTY / OCCUPY / DUMMY
string key[M];
int val[M];

int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}

// key[idx] == k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// key에 대응되는 value를 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k){
  int idx = my_hash(k);
  while(status[idx] != EMPTY){
    if(status[idx] == OCCUPY && key[idx] == k) return idx;
    idx = (idx+1) % M; //범위 처리
  }
  return -1; //EMPTY를 만날 경우 값이 없는 것이므로 -1 반환
}

void insert(string k, int v){
  int idx = find(k);
  if(idx != -1){ //이미 존재하면 값 갱신
    val[idx] = v;
    return;
  }
  idx = my_hash(k);
  while(status[idx] == OCCUPY) // DUMMY나 EMPTY가 나올때까지 인덱스 이동
    idx = (idx+1) % M;
  // 인덱스 자리에 갱신
  key[idx] = k;
  val[idx] = v;
  status[idx] = OCCUPY;
}

void erase(string k){
  int idx = find(k);
  if(idx != -1) status[idx] = DUMMY;
}

void test(){
  insert("orange", 724); // ("orange", 724)
  insert("melon", 20); // ("orange", 724), ("melon", 20)
  assert(val[find("melon")] == 20);
  insert("banana", 52); // ("orange", 724), ("melon", 20), ("banana", 52)
  insert("cherry", 27); // ("orange", 724), ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 100); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(val[find("banana")] == 52);
  assert(val[find("orange")] == 100);
  erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(find("orange") == -1);
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 15); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15)
  assert(val[find("orange")] == 15);
  insert("apple", 36); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36)
  insert("lemon", 6); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36), ("lemon", 6)
  insert("orange", 701);  // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 701), ("apple", 36), ("lemon", 6)
  assert(val[find("cherry")] == 27);
  erase("xxxxxxx");
  assert(find("xxxxxxx") == -1);
  assert(val[find("apple")] == 36);
  assert(val[find("melon")] == 20);
  assert(val[find("banana")] == 52);
  assert(val[find("cherry")] == 27);
  assert(val[find("orange")] == 701);
  assert(val[find("lemon")] == 6);  
  cout << "good!\n";  
}

int main(){
  fill(status, status+M, EMPTY);
  test();
}