#include <bits/stdc++.h>
using namespace std;
void solve() 
{
    int l; int r;
    cin >> l >> r;
    cout << (long long)r * (r + 1) << endl;
    int ans[r + 1];
    if (r == 0) 
    {
        cout << 0 << endl;
    } 
    else if (r == 1) 
    { 
        cout << "1 0" << endl;  
    }
    else if (r == 2) 
    {      
        cout << "0 2 1" << endl;  
    } 
    else
    {
        long long reference;
        int k;
        for (int i = 0; i < r; i ++)
        {
            if (pow(2, i) > r)
            {
                reference = pow(2, i);
                k = i;
                break;
            }
        }
        int breaker = r;
        for (int i = r; i >= 0; i--)
        {
            if (reference - i - 1 <= breaker)
            {
                ans[i] = reference - i - 1;
            }
            else
            {
                breaker = i;
                while (reference - i - 1 > breaker)
                {
                    reference = pow(2, --k);
                }
                ans[i] = reference - i - 1;
            }
        }
        for (int i = 0; i < r + 1; i++)
        {
            cout << ans[i] << " ";
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