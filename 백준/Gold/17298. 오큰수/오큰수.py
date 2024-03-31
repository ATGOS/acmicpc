import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().rstrip().split()))
p = [-1] * n;l = []
l.append(0)
for i in range(1, n):
    while len(l) != 0 and a[l[-1]] < a[i]: p[l.pop()] = a[i]
    l.append(i)
print(*p)