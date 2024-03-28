n, m = map(int, input().split())
l = [x+1 for x in range(n)]
for x in range(m) :
    i, j = map(int, input().split())
    l = l[:i-1] + list(reversed(l[i-1:j])) + l[j:]
print(*l)