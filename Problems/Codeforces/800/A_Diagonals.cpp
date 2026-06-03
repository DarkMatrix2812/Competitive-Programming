#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
void solve()
{
    int n; int k;
    cin >> n >> k;
    int diagonal = 0;
    int start = n;
    while (k > 0)
    {
        if (start == n)
        {
            k -= start;
            diagonal += 1;
            start -= 1;
        }
        else
        {
            k -= start;
            diagonal += 1;
            if (k <= 0) break;
            k -= start;
            diagonal += 1;
            start -= 1;
        }
    }
    cout << diagonal << endl;
}
int main() 
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