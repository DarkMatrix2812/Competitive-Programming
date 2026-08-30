#include <bits/stdc++.h>
using namespace std;
void solve() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> count;
    for (int i : arr)
    {
        count[i] += 1;
    }
    vector<int> freq;
    for (auto &pair : count)
    {
        freq.push_back(pair.second);
    }
    sort(freq.begin(), freq.end());
    int maximum = 0;
    for (int i = 0; i < freq.size(); i ++)
    {
        int ans = 0;
        for (int j = 0; j < freq.size(); j ++)
        {
            if (freq[j] >= freq[i])
            ans += freq[i];
        }
        maximum = max(ans, maximum);
    }
    cout << maximum << endl;
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