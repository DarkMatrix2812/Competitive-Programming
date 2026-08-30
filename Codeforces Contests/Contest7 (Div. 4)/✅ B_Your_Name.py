def solve():
    n = int(input())
    s1, s2 = input().split()
    s1 = list(s1)
    s2 = list(s2)
    if sorted(s1) == sorted(s2):
        print("YES")
    else:
        print("NO")
t = int(input())
for i in range(t):
    solve()