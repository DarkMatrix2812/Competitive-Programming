#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s1, s2;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] != i + 1) s1.insert(i + 1);
        if (a[i] != n - i) s2.insert(i + 1);
    }
    int turn = 1;
    set<int> intersection;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(intersection, intersection.begin()));
    set<int> onlys1;
    set_difference(s1.begin(), s1.end(), intersection.begin(), intersection.end(), inserter(onlys1, onlys1.end()));   
    set<int> onlys2;
    set_difference(s2.begin(), s2.end(), intersection.begin(), intersection.end(), inserter(onlys2, onlys2.end())); 
    while (!s1.empty() && !s2.empty())
    {
        if (turn % 2 == 1) //Player 1's turn
        {
            if (!onlys1.empty()) // Deleting elements only present in s1 first
            {
                auto it = onlys1.begin();
                int x = *it;
                onlys1.erase(it);
                s1.erase(x);
            }
            else // Forced to delete common elements now
            {
                auto it = s1.begin();
                int x = *it;
                s1.erase(it);
                s2.erase(x); 
            }
        }
        else //Player 2's turn
        {
            if (!onlys2.empty()) // Deleting elements only present in s2 first
            {
                auto it = onlys2.begin();
                int x = *it;
                onlys2.erase(it);
                s2.erase(x);
            }
            else // Forced to delete common elements now
            {
                auto it = s2.begin();
                int x = *it;
                s2.erase(it);
                s1.erase(x); 
            }
        }
        turn += 1;
    }
    if (s1.empty() && s2.empty()) cout << "Tie" << endl;
    else if (s1.empty()) cout << "First" << endl;
    else cout << "Second" << endl;
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