import sys
import math
def C(n, r):
    if r < 0 or n < 0 or r > n:
        return 0
    return math.comb(n, r)
def ways(n, s):
    ans = 0
    limit = (s - n) // 6
    for i in range(limit + 1):
        term = C(n, i) * C(s - 6 * i - 1, n - 1)
        if i % 2 == 0:
            ans += term
        else:
            ans -= term
    return ans
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    a = int(input_data[1])
    b = int(input_data[2])
    ans = 0
    for i in range(a, b + 1):
        ans += ways(n, i)
    denom = 6 ** n
    prob = float(ans) / float(denom)
    print(f"{prob:.6f}")

if __name__ == '__main__':
    solve()