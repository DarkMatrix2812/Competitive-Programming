#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n; int m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> black;
    for (int i = 0; i < m; i++) 
    {
        int x;
        cin >> x;
        black.insert(x);
    }
    int curr = 1;
    for (int i = 0; i < s.length(); i ++)
    {
        if(i > 0)
        {
			if(s[i - 1] == 'B')
            {
				while(black.count(curr)) 
                curr += 1;
			}
		}
        if (s[i] == 'A')
        curr += 1;
        else
        {
            curr += 1;
            while (black.count(curr))
            curr += 1;
        }
        black.insert(curr);
    }
    cout << black.size() << endl;
    for (int i : black)
    {
        cout << i << " ";
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