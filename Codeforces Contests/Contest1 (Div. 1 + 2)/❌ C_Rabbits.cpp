#include <bits/stdc++.h>
using namespace std;
void solve() 
{
    int n; cin >> n;
	string s; cin >> s;
	bool valid = true;
	bool check = (s[0] == '1');
	int count = 0;
	for (int i = 0; i < n; i++) 
    {
		if (s[i] == '0')
			count++;
		if (i == 0)
			continue;
		if (s[i] == s[i-1] && s[i] == '0')
			check = false;
		if (s[i] == s[i-1] && s[i] == '1') 
        {
			if (check == true && count % 2 == 1)
				valid = false;
			check = true;
			count = 0;
		}
	}
	
	if (check == true && count % 2 == 1 && s[n-1] == '1')
		valid = false;
		
	if (valid == true)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
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