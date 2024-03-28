n, m = map(int, input().split())
l = [0]*n
for p in range(m) :
    i, j, k = map(int, input().split())
    for q in range(j - i + 1) :
        l[i - 1 + q] = k
print(*l)