#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
    }
    vector<int> dp1(n);
    dp1[0] = a[0];
    for (int i = 1; i < n; i ++) //Max sub-array sum ending at index i
    {
        dp1[i] = max(a[i], dp1[i - 1] + a[i]);
    }
    if (k % 2 == 0) //Bob can just nullify Alice's move
    {
        cout << *max_element(dp1.begin(), dp1.end()) << endl;
    }
    else //Alice has the game-changing move to make, she has to modify some a_i into a_i + b_i to get the max subarray sum
    {
        vector<int> dp2(n);
        dp2[0] = a[0] + b[0];
        for (int i = 1; i < n; i ++) //Max sub-array sum ending at index i with one modification
        {
            dp2[i] = max(a[i] + b[i], max(dp1[i - 1] + a[i] + b[i], dp2[i - 1] + a[i]));
        }
        cout << *max_element(dp2.begin(), dp2.end()) << endl;
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