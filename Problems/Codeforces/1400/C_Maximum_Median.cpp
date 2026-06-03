#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (k > 0)
    {
        int start = n / 2 + 1;
        int stop = n - 1;
        int index = -1;
        while (start <= stop)
        {
            int mid = (start + stop) / 2;
            if (a[mid] > a[n / 2])
            {
                index = mid;
                stop = mid - 1;
            }
            else start = mid + 1;
        }
        if (index == -1) 
        {
            a[n / 2] += k / (n - n / 2);
            break;
        }
        long long diff = a[index] - a[n / 2];
        long long val = index - n / 2;
        if (k >= diff * val)
        {
            k -= diff * val;
            a[n / 2] = a[index];
        }
        else
        {
            a[n / 2] += k / val;
            break;
        }
    }
    cout << a[n / 2];
}