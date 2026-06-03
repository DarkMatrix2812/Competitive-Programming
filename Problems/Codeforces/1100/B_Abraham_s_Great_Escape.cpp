#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n; int k;
    cin >> n >> k;
    if (k == n * n - 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<vector<char>> grid(n, vector<char>(n, '0'));
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (i == n - 1 && j == n - 1) grid[i][j] = 'U';
            else if (j == n - 1 && i % 2 == 0) grid[i][j] = 'D';
            else if (j == n - 1 && i % 2 != 0) grid[i][j] = 'U';
            else if (j % 2 == 0 && j != n - 1) grid[i][j] = 'R';
            else if (j % 2 != 0 && j != n - 1) grid[i][j] = 'L';
        }
    }
    if (k == 0)
    {
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
        return;
    }
    int count = 0; 
    int index_i = 0;
    int index_j = 0;
    int flag = 0;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            count += 1;
            if (grid[i][j] != 'U') 
            {
                grid[i][j] = 'U';
            }
            if (count == k)
            {
                index_i = i;
                index_j = j;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        break;
    }
    if (k > n * (n - 1) && k < n * n)
    {
        for (int i = n - 1; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (grid[i][j] == 'L')
                grid[i][j] = 'R';
                if (grid[i][j] == 'U' && j == n - 1)
                {
                    grid[i][j] = 'L';
                }
            }
        }
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
        return;
    }
    if (k % n != 0)
    {
        for (int i = index_i; i < n; i ++)
        {
            for (int j = index_j; j < n; j ++)
            {
                if (grid[i][j] == 'L')
                grid[i][j] = 'R';
                if (grid[i][j] == 'U' && i != n - 1 && j == n - 1)
                {
                    grid[i][j] = 'D';
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = index_i + 1; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (grid[i][j] == 'L')
                grid[i][j] = 'R';
                if (grid[i][j] == 'U' && j == n - 1)
                {
                    grid[i][j] = 'L';
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cout << grid[i][j];
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
    //test
}