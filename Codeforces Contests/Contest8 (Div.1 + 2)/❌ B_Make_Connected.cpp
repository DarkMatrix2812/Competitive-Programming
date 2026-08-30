#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
//ABSOLUTE BLOCKBUSTER QUESTION MAN I DON'T KNOW HOW THIS IS DIV.2 B (ok maybe it's Div.1 B)
void solve()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> grid[i];;
    }
    if (n == 1 || n == 2) 
    {
        cout << "YES" << endl;
        return;
    }
    for (string s : grid)
    {
        if (s.find("###") != string::npos)
        {
            cout << "NO" << endl;
            return;
        }
    }
    vector<string> columns;
    for (int i = 0; i < n; i ++)
    {
        string tmp = "";
        for (int j = 0; j < n; j ++)
        {
            tmp += grid[j][i];
        }
        columns.push_back(tmp);
    }
    for (string s : columns)
    {
        if (s.find("###") != string::npos)
        {
            cout << "NO" << endl;
            return;
        }
    }
    int start = 0, stop = 0;
    for (int c = 0; c < n; c++)
    {
        start = n;
        stop = -1;
        for (int i = 0; i < grid[c].length(); i++)
        {
            if (grid[c][i] == '#')
            {
                start = min(start, i);
                stop = max(stop, i);
            }
        }
        if (stop == -1) continue;
        if (stop - start >= 2)
        {
            cout << "NO" << endl; //the case where # is separated by too much, it is impossible to fill the grid optimally
            return;
        }
    }
    start = 0, stop = 0;
    for (int c = 0; c < n; c++)
    {
        start = n;
        stop = -1;
        for (int i = 0; i < columns[c].length(); i++)
        {
            if (columns[c][i] == '#')
            {
                start = min(start, i);
                stop = max(stop, i);
            }
        }
        if (stop == -1) continue;
        if (stop - start >= 2)
        {
            cout << "NO" << endl; //the case where # is separated by too much, it is impossible to fill the grid optimally
            return;
        }
    }
    vector<int> sum;
    vector<int> diff;
    vector<int> x;
    vector<int> y;
    for (int c = 0; c < n; c ++)
    {
        for (int i = 0; i < grid[c].length(); i ++)
        {
            if (grid[c][i] == '#')
            {
                x.push_back(c);
                y.push_back(i);
                sum.push_back(c + i);
                diff.push_back(c - i);
            }
        }
    }
    if (sum.empty()) 
    { 
        cout << "YES" << endl; 
        return; 
    }
    if (*max_element(sum.begin(), sum.end()) - *min_element(sum.begin(), sum.end()) <= 1) //checking if zigzag possible
    {
        cout << "YES" << endl;
        return; 
    }
    if (*max_element(diff.begin(), diff.end()) - *min_element(diff.begin(), diff.end()) <= 1) //checking if zigzag possible
    {
        cout << "YES" << endl;
        return;
    }
    //Now check for 2x2 square grid too, that is edgecase which is valid
    if ((*max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()) <= 1 && *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end()) <= 1))
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}
int32_t main() 
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