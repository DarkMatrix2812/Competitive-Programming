t = int(input())
for _ in range(t):
    n, k = list(map(int,input().split()))
    s = input().strip()
    c0 = s.count('0')
    c1 = s.count('1')
    c2 = s.count('2')
    l0 = 1 + c0
    r0 = n - c1
    if n == k:
        print('-' * n)
        continue
    left_plus = l0 + c2
    right_plus = r0 - c2
    res = []
    for i in range(1, n + 1):
        if i < l0 or i > r0:
            res.append('-')
        elif left_plus <= right_plus and left_plus <= i <= right_plus:
            res.append('+')
        else:
            res.append('?')
    print(''.join(res))