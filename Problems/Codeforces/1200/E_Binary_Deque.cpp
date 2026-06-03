#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n; int s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    int left = 0; int right = n - 1;
    if (sum == s)
    {
        cout << 0 << endl;
        return;
    }
    if (sum < s)
    {
        cout << -1 << endl;
        return;
    }
    map<ll, int> firstIndex;
    ll prefSum = 0;
    int ans = 0;
    for(int i = 0; i < a.size(); i ++)
    {
        prefSum += a[i];
        if (prefSum == s)
        ans = i + 1;
        if (firstIndex.count(prefSum - s))
        ans = max(ans, i - firstIndex[prefSum - s]);
        if (!firstIndex.count(prefSum))
        firstIndex[prefSum] = i;
    }
    cout << n - ans << endl;
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