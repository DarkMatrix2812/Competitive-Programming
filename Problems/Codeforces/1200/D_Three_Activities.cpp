#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<int> findMax3(vector<int> &arr) 
{
	vector<pair<int, int>> tmp; 
	for (int i = 0; i < arr.size(); i++) 
    { 
		tmp.push_back({arr[i], i});
	}
	sort(tmp.rbegin(), tmp.rend());
	vector<int> ans;
	for (int i = 0; i < 3; i++)
	{
        ans.push_back(tmp[i].second);
    }
	return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ski(n);
    vector<int> movie(n);
    vector<int> board_game(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> ski[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> movie[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> board_game[i];
    }
    vector<int> max_ski = findMax3(ski);
	vector<int> max_movie = findMax3(movie);
	vector<int> max_board_game = findMax3(board_game);
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int x = max_ski[i];
                int y = max_movie[j];
                int z = max_board_game[k];
                if (x != y && y != z && x != z)
                {
                    ans = max(ans, ski[x] + movie[y] + board_game[z]);
                }
            }
        }
    }
    cout << ans << endl;
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