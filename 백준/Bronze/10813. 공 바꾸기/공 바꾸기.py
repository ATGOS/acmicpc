n, m = map(int, input().split())
l = list(range(1, n+1))
for p in range(m) :
    i, j = map(int, input().split())
    k = l[i-1];l[i-1] = l[j-1];l[j-1] = k
print(*l)