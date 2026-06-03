#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int query(int type, int l, int r) 
{
    cout << type << " " << l << " " << r << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n; 
        cin >> n;
        ll total_p = query(1,1,n);
        ll total_a = query(2,1,n);
        ll len = total_a - total_p;
        int low = 1, high = n;
        while(low < high)
        {
            int mid = (low + high)/2;
            ll val1 = query(1, low, mid);
            ll val2 = query(2, low, mid);
            if(val2 - val1 > 0) 
            high = mid;
            else 
            low = mid + 1;
        }
        cout << "! " << low << " " << low + len - 1 << endl;
        cout.flush();
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