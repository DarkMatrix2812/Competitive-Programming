#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int N = s.length();
    if (s.find('0') != string::npos)
    {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    if (s.find('8') != string::npos)
    {
        cout << "YES" << endl;
        cout << 8 << endl;
        return;
    }
    for (int i = 0; i < N; i ++)
    {
        for (int j = i + 1; j < N; j ++)
        {
            if (s[i] != '0')
            {
                string tmp;
                tmp.push_back(s[i]);
                tmp.push_back(s[j]);
                int num = stoi(tmp);
                if (num % 8 == 0) 
                {
                    cout << "YES" << endl;
                    cout << num << endl;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < N; i ++)
    {
        for (int j = i + 1; j < N; j ++)
        {
            for (int k = j + 1; k < N; k ++)
            {
                if (s[i] != '0')
                {
                    string tmp;
                    tmp.push_back(s[i]);
                    tmp.push_back(s[j]);
                    tmp.push_back(s[k]);
                    int num = stoi(tmp);
                    if (num % 8 == 0) 
                    {
                        cout << "YES" << endl;
                        cout << num << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}