#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;

    //배열 사용 x
    // for(char a='a';a<='z';a++){
    //     int cnt = 0;
    //     for(char c:s){
    //         if(c==a)
    //             cnt++;
    //     }
    //     cout<<cnt<<' ';
    // }

    //배열 사용 o
    int freq[26];
    fill(freq, freq+26, 0);
    for(auto c:s){
        freq[c-'a']++;
    }
    for(auto i: freq)
        cout<<i<<' ';


    return 0;
}