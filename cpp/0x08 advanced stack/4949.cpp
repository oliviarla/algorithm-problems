#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string str;
        getline(cin,str);
        stack<char> st;
        if (str == ".") break; // 마침표 나오면 입력 끝
        bool correct = true;
        for (char c : str){
            //여는 괄호만 스택에 추가
            if (c == '(' || c == '[') st.push(c);
            else if (c == ')'){
                if (st.empty() || st.top()!='('){
                    correct = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']'){
                if (st.empty()||st.top()!='['){
                    correct = false;
                    break;
                }
                st.pop();
            }
        }
        if (st.empty() && correct)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}