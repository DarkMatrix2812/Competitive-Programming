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
int getRoot(int x, int y) 
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
struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, long long val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
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
/*Time limit per test: 2.0 seconds
Memory limit per test: 256 megabytes
You are given an array A of n integers.
For any contiguous subarray A[l, r], we define its multiplicative value P[l, r] as the product of all elements in the subarray, modulo 10^9 + 7
P[l, r] = product(A_i) mod (10^9 + 7)
You construct a new array b of length n(n + 1)/2 by writing down the multiplicative values of all contiguous subarrays of A. 
You process the subarrays primarily in increasing order of their left endpoint L, and secondarily in increasing order of their right endpoint R.
For example, if n = 3, the array B is formed by appending the values: P(1, 1), P(1, 2), P(1, 3), P(2, 2), P(2, 3), P(3, 3). You are given Q queries. 
Each query consists of two integers x and y. For each query, you need to find the sum of elements B_x + B_(x + 1) + ... + B_y, modulo 10^9 + 7.
Expected time complexity: O(nlogM + q(logn + logM))*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // P = Non-zero prefix product (pretends 0s are 1s so the chain doesn't break)
    // SP = Prefix sum of the prefix products
    // nextZero = Tracks the closest zero to the right
    vector<int> P(n + 1, 1);
    vector<int> SP(n + 1, 0);
    vector<int> nextZero(n + 2, n + 1);
    for (int i = 1; i <= n; i++) 
    {
        if (a[i - 1] == 0) 
        {
            P[i] = P[i - 1];
        } 
        else 
        {
            P[i] = (P[i - 1] * a[i - 1]) % MOD;
        }
        SP[i] = (SP[i - 1] + P[i]) % MOD;
    }
    // Traverse backwards. For any index i, nextZero[i] tells us where 
    // the subarray product will inevitably collapse to 0.
    int lastZero = n + 1;
    for (int i = n; i >= 1; i--) 
    {
        if (a[i - 1] == 0) lastZero = i;
        nextZero[i] = lastZero;
    }
    // PrefRow[i] stores the sum of all valid products from Row 1 up to Row i.
    vector<int> PrefRow(n + 1, 0);
    for (int i = 1; i <= n; i++) 
    {
        int limit = nextZero[i] - 1; // Cap calculation right before the zero
        int rowSum = 0; 
        // If limit >= i, the row has at least one valid non-zero subarray       
        if (limit >= i) 
        {
            int inv = modinv(P[i - 1], MOD);
            int sumP = (SP[limit] - SP[i - 1] + MOD) % MOD;
            rowSum = (sumP * inv) % MOD;
        }
        PrefRow[i] = (PrefRow[i - 1] + rowSum) % MOD;
    }
    auto get_prefix_sum = [&](int pos) -> int 
    {
        if (pos == 0) return 0;
        int low = 0, high = n, k = 0;
        // Binary search to find 'k', the exact number of completely full rows.
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            if (mid * n - mid * (mid - 1) / 2 + 1 <= pos) 
            {
                k = mid;
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }
        int ans = PrefRow[k]; // Grab the sum of all 'k' full rows in O(1) time
        int rem = pos - (k * n - k * (k - 1) / 2); // Calculate leftover elements spilling into the partial row (k + 1)
        if (rem > 0) 
        {
            int end = rem + k;
            // Set the right boundary to either the end OR the nearest zero, whichever comes first.
            int limit = min(end, nextZero[k + 1] - 1); 
            // If we haven't crossed a zero, calculate the partial sum
            if (limit >= k + 1) 
            {
                int sumP = (SP[limit] - SP[k] + MOD) % MOD;
                ans = (ans + (sumP * modinv(P[k], MOD)) % MOD) % MOD;
            }
        }
        return ans;
    };
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << (get_prefix_sum(r) - get_prefix_sum(l - 1) + MOD) % MOD << endl; // Our final answer
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