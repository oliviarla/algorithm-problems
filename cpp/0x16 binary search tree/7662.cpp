#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        multiset<int> s;
        int k;
        cin >> k;
        while (k--)
        {
            char c;
            cin >> c;
            if (c == 'I')
            {
                int n;
                cin >> n;
                s.insert(n);
            }
            else
            {
                int n;
                cin >> n;
                if (s.empty()) continue;
                if (n == 1) s.erase(prev(s.end())); //최댓값 삭제
                else s.erase(s.begin()); //최솟값 삭제
            }
        }
        if (s.empty())
            cout << "EMPTY" << '\n';
        else
        {
            cout << *prev(s.end()) << ' ' << *s.begin() << '\n'; //최댓값과 최솟값 출력
        }
    }
}