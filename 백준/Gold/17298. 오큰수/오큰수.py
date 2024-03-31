import sys
n = int(input())
a = list(map(int, sys.stdin.readline().rstrip().split()))
p = [-1] * n;l = []
l.append(0)
for i in range(1, n):
    while len(l) != 0 and a[l[-1]] < a[i]: p[l.pop()] = a[i]
    l.append(i)
print(*p)