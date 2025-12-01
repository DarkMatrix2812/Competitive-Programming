#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; int j; int k;
    cin >> n >> j >> k;
    vector<int> p1 = {12, 21};
    vector<int> p2 = {123, 132, 213, 231, 312, 321};
    vector<int> p3 = {1234, 1243, 1324, 1342, 1423, 1432, 2134, 2143, 2314, 2341, 2413, 2431, 3124, 3142, 3214, 3241, 3412, 3421, 4123, 4132, 4213, 4231, 4312, 4321};
    if (n == 12)
    {
        string s1 = to_string(p1[j - 1]);
        string s2 = to_string(p1[k - 1]);
        int A = 0; int B = 0;
        for (int i = 0; i < s1.length(); i ++)
        {
            for (int j = 0; j < s2.length(); j ++)
            {
                if (s1[i] == s2[j] && i == j)
                {
                    A += 1;
                    break;
                }
                else if (s1[i] == s2[j] && i != j)
                {
                    B += 1;
                    break;
                }
            }
        }
        cout << A << "A" << B << "B" << endl;
    }
    else if (n == 123)
    {
        string s1 = to_string(p2[j - 1]);
        string s2 = to_string(p2[k - 1]);
        int A = 0; int B = 0;
        for (int i = 0; i < s1.length(); i ++)
        {
            for (int j = 0; j < s2.length(); j ++)
            {
                if (s1[i] == s2[j] && i == j)
                {
                    A += 1;
                    break;
                }
                else if (s1[i] == s2[j] && i != j)
                {
                    B += 1;
                    break;
                }
            }
        }
        cout << A << "A" << B << "B" << endl;
    }
    else
    {
        string s1 = to_string(p3[j - 1]);
        string s2 = to_string(p3[k - 1]);
        int A = 0; int B = 0;
        for (int i = 0; i < s1.length(); i ++)
        {
            for (int j = 0; j < s2.length(); j ++)
            {
                if (s1[i] == s2[j] && i == j)
                {
                    A += 1;
                    break;
                }
                else if (s1[i] == s2[j] && i != j)
                {
                    B += 1;
                    break;
                }
            }
        }
        cout << A << "A" << B << "B" << endl;
    }
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}   