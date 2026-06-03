#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    set<int> diffs;
    for (int i = 1; i < n; i++)
    {
        diffs.insert(nums[i] - nums[i - 1]);
    }
    if (diffs.size() == 1)
    {
        set<int> ans;
        if (n == 2 && *diffs.begin() % 2 == 0)
        {
            ans.insert(nums[0] - *diffs.begin());
            ans.insert((nums[0] + nums[1]) / 2);
            ans.insert(nums[1] + *diffs.begin());
            cout << ans.size() << endl;
            for (int a : ans)
            {
                cout << a << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            ans.insert(nums[0] - *diffs.begin());
            ans.insert(nums[n - 1] + *diffs.begin());
            cout << ans.size() << endl;
            for (int a : ans)
            {
                cout << a << " ";
            }
            cout << endl;
            return;
        }
    }
    else if (diffs.size() == 2)
    {
        int g = *diffs.begin();
        for (int d : diffs)
        {
            g = gcd(g, d);
        }
        if (g == 1 && (diffs.count(1) == false || diffs.count(2) == false))
        {
            cout << 0 << endl;
            return;
        }
        // what if sequence is something like 2, 8, 16? the gcd is 2 but how do we insert only 1 element and make it AP?
        // the key is that we need one and only one occurence to be an immediate multiple of gcd
        //only then can we insert ONE element
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == g * 2)
            {
                count += 1;
            }
        }
        if (count == 1)
        {
            cout << 1 << endl;
            for (int i = 1; i < n; i++)
            {
                if (nums[i] - nums[i - 1] == g * 2)
                {
                    cout << nums[i - 1] + g << endl;
                    return;
                }
            }
        }
        else
        {
            cout << 0 << endl;
            return;
        }
    }
    else
    {
        cout << 0 << endl;
        return;
    }
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}