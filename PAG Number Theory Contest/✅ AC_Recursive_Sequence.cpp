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
#define MOD 1000000000
#define MOD2 998244353
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
void solve()
{
    int k;
    cin >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i ++)
    {
        cin >> a[i];
    }
    vector<int> c(k + 1);
    for (int i = 1; i <= k; i ++)
    {
        cin >> c[i];
    }
    int n;
    cin >> n;
    if (n <= k)
    {
        cout << a[n] % MOD << endl;
        return;
    }
    Matrix A(k, k);
    for (int j = 0; j < k; j ++)
    {
        A.mat[0][j] = c[j + 1];
    }
    for (int i = 1; i < k; i ++)
    {
        A.mat[i][i - 1] = 1;
    }
    Matrix B = matrixExp(A, n - k);
    int ans = 0;
    for (int i = 0; i < k; i ++)
    {
        ans = (ans + B.mat[0][i] * a[k - i] % MOD) % MOD;
    }
    cout << ans % MOD << endl;
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