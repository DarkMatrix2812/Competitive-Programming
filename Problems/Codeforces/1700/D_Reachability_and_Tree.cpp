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

// --- MATH ---
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

// --- GRAPHS ---
vector<vector<int>> adj;
vector<int> d, p;
vector<bool> vis;
// d.assign(n + 1, -1);
// p.assign(n + 1, -1);
// vis.assign(n + 1, false);
void bfs(int s)
{
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
// color.assign(n + 1, 0);
// tin.assign(n + 1, -1);
// tout.assign(n + 1, -1);
void iterative_dfs(int root)
{
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
vector<vector<pair<int,int>>> adjd;
vector<int> dist;
// dist.assign(n + 1, LLONG_MAX);
void dijkstra(int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty())
    {
        auto [d, v] = pq.top();
        pq.pop();
        if(d != dist[v]) continue;
        for(auto [u, w] : adjd[v])
        {
            if(dist[u] > d + w)
            {
                dist[u] = d + w;
                pq.push({dist[u], u});
            }
        }
    }
}
// dist.assign(n + 1, LLONG_MAX);
// p.assign(n + 1, -1);
void bfs01(int s) // basically dijkstra but optimized because we have weights only as 0-1
{
    deque<int> q;
    dist[s] = 0;
    q.push_front(s);
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for(auto [u, w] : adjd[v])
        {
            if(dist[v] + w < dist[u])
            {
                dist[u] = dist[v] + w;
                p[u] = v;
                if(w == 1)
                {
                    q.push_back(u);
                }
                else
                {
                    q.push_front(u);
                }
            }
        }
    }
}
vector<vector<pair<int,int>>> adjbf;
vector<int> bellman_dist;
// adjbf.assign(n + 1, {});
// bellman_dist.assign(n + 1, LLONG_MAX);
void bellmanFord(int n, int s)
{
    bellman_dist.assign(n + 1, LLONG_MAX);
    bellman_dist[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for(int u = 1; u <= n; u++)
        {
            if (bellman_dist[u] == LLONG_MAX) continue;
            for (auto [v, w] : adjbf[u])
            {
                if (bellman_dist[v] > bellman_dist[u] + w)
                {
                    bellman_dist[v] = bellman_dist[u] + w;
                }
            }
        }
    }
}
// for (int u = 1; u <= n; u++)
// {
//     if (bellman_dist[u] == LLONG_MAX) continue;
//     for (auto [v, w] : adjbf[u])
//     {
//         if (bellman_dist[v] > bellman_dist[u] + w)
//         {
//             // Negative cycle detected.
//             // Handle according to the problem.
//         }
//     }
// }

// --- DSU ---
vector<int> parent;
vector<int> sz; 
void make_set(int v) 
{
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) 
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) 
    {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

// --- FENWICK TREE (BIT) ---
int bit_n;
vector<int> bit_arr;
// bit_n = n;
// bit_arr.assign(bit_n + 1, 0);
void fenwick_update(int i, int val) 
{
    for (; i <= bit_n; i += i & -i) bit_arr[i] += val;
}
int fenwick_query(int i) 
{
    int sum = 0;
    for (; i > 0; i -= i & -i) sum += bit_arr[i];
    return sum;
}

// --- MATRIX OPERATIONS ---
vector<vector<int>> identityMatrix(int n) 
{
    vector<vector<int>> I(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) I[i][i] = 1;
    return I;
}
vector<vector<int>> matrixMultiply(vector<vector<int>> &A, vector<vector<int>> &B) 
{
    int n = A.size(), m = B[0].size(), K = A[0].size();
    vector<vector<int>> product(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int k = 0; k < K; k++) 
        {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < m; j++) 
            {
                product[i][j] = (product[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return product;
}
vector<vector<int>> matrixExp(vector<vector<int>> base, int exp) 
{
    vector<vector<int>> result = identityMatrix(base.size());
    while (exp > 0) 
    {
        if (exp & 1) result = matrixMultiply(result, base);
        base = matrixMultiply(base, base);
        exp >>= 1;
    }
    return result;
}

// --- SPARSE TABLE ---
int st_n, max_log;
vector<vector<int>> st_min, st_max;
vector<int> log_table;
void buildSparseTable(vector<int>& a) 
{
    st_n = a.size();
    log_table.assign(st_n + 1, 0);
    for (int i = 2; i <= st_n; i++) log_table[i] = log_table[i / 2] + 1;
    max_log = log_table[st_n] + 1; 
    st_min.assign(st_n, vector<int>(max_log));
    st_max.assign(st_n, vector<int>(max_log));
    for (int i = 0; i < st_n; i++) 
    {
        st_min[i][0] = a[i];
        st_max[i][0] = a[i];
    }
    for (int j = 1; j < max_log; j++) 
    {
        for (int i = 0; i + (1 << j) <= st_n; i++) 
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
    // REMEMBER TO ASSIGN IF NEEDED!!!!!!
    // from every node to another gives us n - 1 directly
    // keep flipping directions other than the one vertex with deg 2
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i ++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> deg(n + 1, 0);
    int root = -1;
    for (int node = 1; node <= n; node ++)
    {
        deg[node] = adj[node].size();
        if (deg[node] == 2) root = node;
    }
    if (root == -1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pair<int, int>> ans;
    ans.push_back({root, adj[root][0]});
    ans.push_back({adj[root][1], root});
    vis.assign(n + 1, false);
    p.assign(n + 1, -1);
    vis[root] = true;
    queue<int> q;
    q.push(adj[root][0]);
    vis[adj[root][0]] = true;
    vector<int> type(n + 1, 0);
    type[adj[root][0]] = false;
    vis[adj[root][0]] = true;
    q.push(adj[root][0]);
    type[adj[root][1]] = true;
    vis[adj[root][1]] = true;
    q.push(adj[root][1]);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = true;
                if (type[v] == 1) 
                {
                    ans.push_back({v, u});
                    type[u] = 2;
                } 
                else 
                {
                    ans.push_back({u, v});
                    type[u] = 1;
                }
                q.push(u);
            }
        }
    }
    for (auto &p : ans)
    {
        cout << p.first << " " << p.second << endl;
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