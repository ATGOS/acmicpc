t = int(input())
for _ in range(t):
    ans = 1
    d = {}
    n = int(input())
    for i in range(n):
        a, b = input().split()
        if b in d.keys():
            d[b].append(a)
        else:
            d[b] = [a]
    for u, v in d.items():
        ans *= (len(v) + 1)
    print(ans-1)