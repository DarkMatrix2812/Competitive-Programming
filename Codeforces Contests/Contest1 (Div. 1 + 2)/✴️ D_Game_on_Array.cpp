#include <bits/stdc++.h>
using namespace std;
void solve()
   {    
        int n;
        cin >> n;
        vector<long long> l(n);
        for (int i = 0; i < n; i++) cin >> l[i];
        unordered_map<long long, long long> freq;
        freq.reserve(n * 2);
        for (auto x : l) freq[x]++;
        vector<pair<long long, long long>> count(freq.begin(), freq.end());
        sort(count.begin(), count.end(), [](auto &a, auto &b) {
                 return a.second > b.second;
             });
        long long alice_points = 0, bob_points = 0;
        long long alice_turns = 0, bob_turns = 0;
        for (auto [num, f] : count) {
            if (num % 2 == 0) {
                alice_points += (f * (num / 2));
                bob_points   += (f * (num / 2));
                alice_turns  += (num / 2);
                bob_turns    += (num / 2);
            } else {
                if (bob_turns > alice_turns) {
                    bob_points   += (num / 2) * f;
                    alice_points += ((num / 2) + 1) * f;
                    alice_turns  += (num / 2) + 1;
                    bob_turns    += (num / 2);
                } else {
                    bob_points   += ((num / 2) + 1) * f;
                    alice_points += (num / 2) * f;
                    alice_turns  += (num / 2);
                    bob_turns    += (num / 2) + 1;
                }
            }
        }
        cout << bob_points << " " << alice_points << "\n";
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