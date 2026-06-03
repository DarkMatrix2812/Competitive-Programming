#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> factors;
    //we greedily find factors, store in a set to avoid duplicates and ONLY if there are >=2 distinct factors do we print YES
    for (int i = 2; i * i <= n; i ++)
    {
        if (n % i == 0 && factors.count(i) == 0)
        {
            factors.insert(i);
            n /= i;
            break;
        }
    }
    for (int i = 2; i * i <= n; i ++)
    {
        if (n % i == 0 && factors.count(i) == 0)
        {
            factors.insert(i);
            n /= i;
            break;
        }
    }
    if (factors.size() < 2 || n == 1 || factors.count(n))
    {
        cout << "NO" << endl;
    }
    else
    {
        factors.insert(n);
        cout << "YES" << endl;
        for (int f : factors)
        {
            cout << f << " ";
        }
        cout << endl;
    }
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