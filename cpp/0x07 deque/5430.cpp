#include <bits/stdc++.h>
using namespace std;

//입력, 출력 부분에서 c++ 사용하는 것이 어려웠음
//변수 사용해서 효율적으로 연산할 수 있도록 하는게 포인트!

//[2,5,6] 형식으로 받은 입력 split해서 deque에 저장하는 함수
void parse(string& tmp, deque<int>& d){
    int cur=0;
    for(int i=1;i+1<tmp.size();i++){
        if(tmp[i]==','){
            d.push_back(cur);
            cur=0;
        }
        else{
            cur=10*cur+(tmp[i]-'0');
        }
    }
    if(cur!=0)
        d.push_back(cur);
}

//[2,5,6] 형식으로 출력하기 위한 함수
void print_result(deque<int>& d){
    cout<<'[';
    for(int i=0;i<d.size();i++){
        cout<<d[i];
        if (i+1!=d.size()) //마지막 원소가 아닐때만
            cout<<',';
    }
    cout<<"]\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;

    while(T--){
        string query, arr;
        int n;
        
        deque<int> dq;
        cin>>query;
        cin>>n;
        cin>>arr;
        parse(arr, dq);

        int rev=0; //배열 뒤집을지 결정하는 변수
        bool isError=false; //error 발생하는지 확인하는 변수

        for(char c:query){
            if (c=='R'){
                //배열 순서 직접 뒤집기보다는 변수 사용해 한번에 뒤집음
                rev = 1-rev;
            }
            else{
                //첫번째 숫자 버리기
                if (!dq.empty()) {
                    if (rev) dq.pop_back();
                    else dq.pop_front();
                }
                else {
                    isError=true;
                    break;
                }
            }
        }
        if(isError){
            cout<<"error\n";
        }
        else{
            if (rev) reverse(dq.begin(), dq.end());
            print_result(dq);
        }
            
    }
}