#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ll ref = nums[0];
    ll ans = 0;
    ll tmp = 0;
    for (int i = 1; i < nums.size(); i ++) 
    {
        if (nums[i] == 1 && ref > 1) 
        {
            cout << -1 << endl;
            return;
        }
        double justice = log2(log(ref) / log(nums[i]));
        justice += tmp;
        if (justice >= 0)
        {
            tmp = ceil(justice);
            ans += tmp;
        }
        else 
        {
            tmp = 0;
        }
        ref = nums[i];
    }
    cout << ans << endl;
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