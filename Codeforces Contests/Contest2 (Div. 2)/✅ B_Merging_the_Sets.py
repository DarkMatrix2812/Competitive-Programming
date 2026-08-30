def solve():
    n, m = map(int, input().split())
    sets = []
    count = [0] * (m + 1)
    for i in range(n):
        l = list(map(int, input().split()))
        L, s = l[0], l[1:]
        sets.append(set(s))
        for x in s:
            count[x] += 1
    flag = 0
    for i in range(1, m + 1):
        if count[i] == 0:
            flag = 1
            break
    o = 0
    for s in sets:
        breaker = 0
        for x in s:
            if count[x] == 1:
                breaker = 1
                break
        if breaker == 0:
            o += 1
    if o >= 2 and flag == 0:
        print("YES")
    else:
        print("NO")
t = int(input())
for i in range(t):
    solve()