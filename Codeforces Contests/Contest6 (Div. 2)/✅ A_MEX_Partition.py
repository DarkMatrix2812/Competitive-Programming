t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr = set(arr)
    if 0 not in arr:
        print(0)
        continue
    for i in range(100):
        if i not in arr:
            print(i)
            break
    