#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
vector<int> fact, invfact;
int binExp(int base, int exp, int M) 
{
    int result = 1;
    while (exp > 0) 
    {
        if (exp % 2 == 1) result = (result * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return result;
}
void build_fact(int N, int M) 
{
    fact = vector<int>(N + 1, 0);
    invfact = vector<int>(N + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i % M;
    }
    invfact[N] = binExp(fact[N], M - 2, M);
    for (int i = N - 1; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1) % M;
    }
}
int nCr(int n, int r, int M) 
{
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % M * invfact[n - r] % M;
}
int nPr(int n, int r, int M) 
{
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % M;
}
int modinv(int a, int M) 
{
    int b = M, u = 1, v = 0;
    while (b) 
    {
        int t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    if (a != 1) return -1;
    u %= M;
    if (u < 0) u += M;
    return u;
}
vector<bool> sieve(int n) 
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; ++p) 
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}
int getRoot(int x, int y) //y-th root of x
{
    int l = 0, h = x, ans = 0;
    while (l <= h) 
    {
        int m = l + (h - l) / 2;
        __int128 cur = 1;
        bool ok = true;
        for (int i = 0; i < y; i ++) 
        {
            cur *= m;
            if (cur > x) 
            {
                ok = false;
                break;
            }
        }
        if (ok) 
        {
            ans = m;
            l = m + 1;
        } 
        else 
        {
            h = m - 1;
        }
    }
    return ans;
}
bool isPerfectSquare(int n) 
{
    if (n < 0) return false;
    int r = getRoot(n, 2);
    return r * r == n;
}
vector<int> factors(int n) 
{
    vector<int> f;
    for (int i = 1; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            f.push_back(i);
            if (i != n / i)
                f.push_back(n / i);
        }
    }
    return f; 
}
vector<int> prefixArr(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i ++) 
    {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    return pref;
}
vector<int> suffixArr(const vector<int>& arr) 
{
    int n = arr.size();
    vector<int> suff(n + 1, 0);
    for (int i = 1; i <= n; i ++) 
    {
        suff[i] = suff[i - 1] + arr[n - i];
    }
    return suff;
}
int gcd(int a, int b)
{
    return (!b ? a : gcd(b, a % b));
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    deque<int> p1, p2, p3;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (i <= x) p1.push_back(a);
        else if (i <= y) p2.push_back(a);
        else p3.push_back(a);
    }
    int m2 = *min_element(p2.begin(), p2.end());
    int m1 = (p1.empty() ? -1 : p1[0]);
    if (m2 < m1)
    {
        while (m2 != p2[0]) // sort p2
        {
            int b = p2.back();
            p2.pop_back();
            p2.push_front(b);
        }
        while (!p1.empty())
        {
            int b = p1.back();
            p1.pop_back();
            p3.push_front(b);
        }
        for (int x : p1)
        {
            cout << x << " ";
        }
        for (int x : p2)
        {
            cout << x << " ";
        }
        for (int x : p3)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        while (m2 != p2[0]) // sort p2
        {
            int b = p2.back();
            p2.pop_back();
            p2.push_front(b);
        }
        if (m1 == -1) // p1 is empty
        {
            while (!p3.empty() && p3.front() < m2)
            {
                int b = p3.front();
                p3.pop_front();
                p1.push_back(b);
            }
            for (int x : p1)
            {
                cout << x << " ";
            }
            for (int x : p2)
            {
                cout << x << " ";
            }
            for (int x : p3)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            int idx = -1;
            for (int i = 0; i < p1.size(); i ++)
            {
                if (p1[i] > m2)
                {
                    idx = i;
                    break;
                }
            }
            if (idx != -1)
            {
                for (int i = p1.size() - 1; i >= idx; i --)
                {
                    p3.push_front(p1[i]);
                }
                for (int i = 0; i < idx; i ++)
                {
                    cout << p1[i] << " ";
                }
                for (int x : p2)
                {
                    cout << x << " ";
                }
                for (int x : p3)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
            else
            {
                while (!p3.empty() && p3.front() < m2)
                {
                    int b = p3.front();
                    p3.pop_front();
                    p1.push_back(b);
                }
                for (int x : p1)
                {
                    cout << x << " ";
                }
                for (int x : p2)
                {
                    cout << x << " ";
                }
                for (int x : p3)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
    }
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