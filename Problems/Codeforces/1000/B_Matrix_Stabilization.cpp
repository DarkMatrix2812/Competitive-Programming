/*
 * ██████╗  █████╗ ██████╗ ██╗  ██╗███╗   ███╗ █████╗ ████████╗██████╗ ██╗██╗  ██╗
 * ██╔══██╗██╔══██╗██╔══██╗██║ ██╔╝████╗ ████║██╔══██╗╚══██╔══╝██╔══██╗██║╚██╗██╔╝
 * ██║  ██║███████║██████╔╝█████╔╝ ██╔████╔██║███████║   ██║   ██████╔╝██║ ╚███╔╝ 
 * ██║  ██║██╔══██║██╔══██╗██╔═██╗ ██║╚██╔╝██║██╔══██║   ██║   ██╔══██╗██║ ██╔██╗ 
 * ██████╔╝██║  ██║██║  ██║██║  ██╗██║ ╚═╝ ██║██║  ██║   ██║   ██║  ██║██║██╔╝ ██╗
 * ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝
 */
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
vector<int> spf;
void buildSPF(int N)
{
    spf.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
vector<int> primeFactors(int n)
{
    vector<int> pf;
    while (n > 1)
    {
        int p = spf[n];
        pf.push_back(p);
        while (n % p == 0)
        {
            n /= p;
        }
    }
    return pf;
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
vector<vector<int>> adj;
vector<int> d, p;
vector<bool> vis;
void bfs(int s)
{
    int n = adj.size();
    d.assign(n, -1);
    p.assign(n, -1);
    vis.assign(n, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    d[s] = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = true;
                d[u] = d[v] + 1;
                p[u] = v;
                q.push(u);
            }
        }
    }
}
vector<int> color, tin, tout;
int timer;
void iterative_dfs(int root)
{
    int n = adj.size();
    color.assign(n, 0);
    tin.assign(n, -1);
    tout.assign(n, -1);
    timer = 0;
    stack<pair<int,int>> st;
    st.push({root, 0}); // 0 = enter, 1 = exit
    while (!st.empty())
    {
        auto [v, state] = st.top();
        st.pop();
        if (state == 0)
        {
            tin[v] = timer++;
            color[v] = 1;
            st.push({v, 1});
            for (int i = (int)adj[v].size() - 1; i >= 0; i--)
            {
                int u = adj[v][i];
                if (color[u] == 0) st.push({u, 0});
            }
        }
        else
        {
            color[v] = 2;
            tout[v] = timer++;
        }
    }
}
void recursive_dfs(int v)
{
    vis[v] = 1;
    for (int u : adj[v])
    {
        if (vis[u]) continue;
        recursive_dfs(u);
    }
}
struct Fenwick 
{
    int n;
    vector<long long> bit;
    Fenwick(int n) 
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int i, long long val) 
    {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }
    long long query(int i) 
    {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
        {
            sum += bit[i];
        }
        return sum;
    }
};
struct Matrix
{
    int n, m;
    vector<vector<int>> mat;
    Matrix(int n, int m)
    {
        this->n = n;
        this->m = m;
        mat.assign(n, vector<int>(m, 0));
    }
};
Matrix identitymatrix(int n)
{
    Matrix I(n, n);
    for (int i = 0; i < n; i++)
    {
        I.mat[i][i] = 1;
    }
    return I;
}
Matrix multiply(Matrix &A, Matrix &B)
{
    Matrix product(A.n, B.m);
    for (int i = 0; i < A.n; i++)
    {
        for (int k = 0; k < A.m; k++)
        {
            if (A.mat[i][k] == 0) continue;
            for (int j = 0; j < B.m; j++)
            {
                product.mat[i][j] += (A.mat[i][k] * B.mat[k][j]) % MOD;
                product.mat[i][j] %= MOD;
            }
        }
    }
    return product;
}
Matrix matrixExp(Matrix base, int exp)
{
    Matrix result = identitymatrix(base.n);
    while (exp > 0)
    {
        if (exp & 1)
        {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}
struct SparseTable 
{
    int n;
    int max_log;
    vector<vector<int>> st_min;
    vector<vector<int>> st_max;
    vector<int> log_table;
    SparseTable(const vector<int>& a) 
    {
        n = a.size();
        log_table.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) 
        {
            log_table[i] = log_table[i / 2] + 1;
        }
        max_log = log_table[n] + 1; 
        st_min.assign(n, vector<int>(max_log));
        st_max.assign(n, vector<int>(max_log));
        for (int i = 0; i < n; i++) 
        {
            st_min[i][0] = a[i];
            st_max[i][0] = a[i];
        }
        for (int j = 1; j < max_log; j++) 
        {
            for (int i = 0; i + (1 << j) <= n; i++) 
            {
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query_min(int L, int R) 
    {
        int j = log_table[R - L + 1];
        return min(st_min[L][j], st_min[R - (1 << j) + 1][j]);
    }
    int query_max(int L, int R) 
    {
        int j = log_table[R - L + 1];
        return max(st_max[L][j], st_max[R - (1 << j) + 1][j]);
    }
};
// number of 1-bits in x
// __builtin_popcountll(x);
// // 1 if popcount is odd, 0 if even
// __builtin_parityll(x);
// // count leading zeros in 64-bit
// __builtin_clzll(x);   // x != 0
// // count trailing zeros (use: lowest set bit, bit iteration)
// __builtin_ctzll(x);   // x != 0
// // index of highest 1-bit (use: power of 2 ≤ x)
// int msb = 63 - __builtin_clzll(x);
// // index of lowest 1-bit
// int lsb = __builtin_ctzll(x);
// // check if power of two
// (x > 0 && (x & (x - 1)) == 0);
// // check k-th bit
// (x >> k) & 1;
// // set k-th bit
// x | (1LL << k);
// // toggle k-th bit
// x ^ (1LL << k);
// // clear k-th bit
// x & ~(1LL << k);
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cin >> a[i][j];
        }
    }
    if (n == 1 && m == 1)
    {
        cout << a[0][0] << endl;
        return;
    }
    if (n == 1)
    {
        for (int j = 0; j < m; j++)
        {
            int mx;
            if (j == 0) mx = a[0][1];
            else if(j == m - 1) mx = a[0][m - 2];
            else mx = max(a[0][j - 1], a[0][j + 1]);
            a[0][j] = min(a[0][j], mx);
        }
    }
    else if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int mx;
            if (i == 0) mx = a[1][0];
            else if (i == n - 1) mx = a[n - 2][0];
            else mx = max(a[i - 1][0], a[i + 1][0]);
            a[i][0] = min(a[i][0], mx);
        }
    }
    else
    {
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                int mx = 0;
                if (i == 0 && j == 0) mx = max(a[0][1], a[1][0]);
                else if (i == 0 && j == m - 1) mx = max(a[0][m - 2], a[1][m - 1]);
                else if (i == n - 1 && j == 0) mx = max(a[n - 2][0], a[n - 1][1]);
                else if(i == n - 1 && j == m - 1) mx = max(a[n - 2][m - 1], a[n - 1][m - 2]);
                else if (i == 0) mx = max({a[i][j - 1], a[i][j + 1], a[i + 1][j]});
                else if (i == n - 1) mx = max({a[i][j - 1], a[i][j + 1], a[i - 1][j]});
                else if (j == 0) mx = max({a[i - 1][j], a[i + 1][j], a[i][j + 1]});
                else if (j == m - 1) mx = max({a[i - 1][j], a[i + 1][j], a[i][j - 1]});
                else mx = max({a[i - 1][j], a[i + 1][j], a[i][j - 1], a[i][j + 1]});
                a[i][j] = min(a[i][j], mx);
            }
        }
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
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