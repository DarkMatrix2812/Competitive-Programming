#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int ans = 0;
        int x; int y;
        cin >> x >> y;
        if (x < y)
        {
            ans = 2;
        }
        else if (x == y || y == 1 || x == y + 1)
        {
            ans = -1;
        }
        else
        {
            ans = 3;
        }
        cout << ans << endl;
    }
}