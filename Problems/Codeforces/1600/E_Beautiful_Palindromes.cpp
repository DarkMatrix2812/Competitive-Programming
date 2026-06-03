#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int missing(int a, int b, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i != a && i != b)
        {
            return i;
        }
    }
}
void solve()
{
    int n; int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // The trick here is that we append 3 elements cyclically to the list, if the list is already a permutation of 1,2,3,..,n
    // then we can simply add the first 3 elements (it will always work as it prevents palindrome)
    // if the list is not a permutation of 1,2,3,..,n then we start with an element that doesn't appear in the list
    vector<bool> present(n + 1, false);
    for (int x : a)
    { 
        present[x] = true;
    }
    int flag = 0; int tmp;
    for (int i = 1; i <= n; i++) 
    {
        if (!present[i]) 
        {
            flag = 1;
            tmp = i;
            break;
        }
}

    if (flag == 1)
    {
        while (true)
        {
            cout << tmp << " ";
            k -= 1;
            if (k == 0) break;
            cout << missing(a[a.size() - 1], tmp, n) << " ";
            k -= 1;
            if (k == 0) break;
            cout << a[a.size() - 1] << " ";
            k -= 1;
            if (k == 0) break;
        }
    }
    else
    {
        while (true)
        {
            cout << a[0] << " ";
            k -= 1;
            if (k == 0) break;
            cout << a[1] << " ";
            k -= 1;
            if (k == 0) break;
            cout << a[2] << " ";
            k -= 1;
            if (k == 0) break;
        }
    }
    cout << endl;
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