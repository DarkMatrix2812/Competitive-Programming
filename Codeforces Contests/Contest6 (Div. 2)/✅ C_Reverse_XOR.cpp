#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
bool is_palindrome(string &str) 
{
    int l = 0, r = str.size() - 1;
    while (l < r) 
    {
        if (str[l++] != str[r--]) 
        return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    if (n == 0) 
    {
        cout << "YES\n";
        return;
    }
    string bin;
    int tmp = n;
    while (tmp) 
    {
        if (tmp & 1 == 1)
        bin += '1';
        else bin += '0';
        tmp >>= 1;
    }
    reverse(bin.begin(), bin.end());
    int trail_zeros = 0;
    for (int i = bin.size() - 1; i >= 0 && bin[i] == '0'; --i) 
    {
        trail_zeros++;
    }
    bool found = false;
    for (int t = 0; t <= trail_zeros && !found; ++t) 
    {
        string candidate(t, '0');
        candidate += bin;
        if (!is_palindrome(candidate)) 
        continue;
        int len = candidate.size();
        if (len % 2 == 0) 
        found = true;
        else if (candidate[len / 2] == '0') 
        found = true;
    }
    if (found)
    cout << "YES" << endl;
    else cout << "NO" << endl;
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