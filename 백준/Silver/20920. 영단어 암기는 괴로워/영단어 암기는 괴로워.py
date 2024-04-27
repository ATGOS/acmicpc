import sys
input = sys.stdin.readline
n, m = map(int, input().split())
d = {}
for _ in range(n):
    a = input().rstrip()
    if a in d: d[a] += 1
    else: d[a] = 1
keys = list(d.keys())
for i in keys:
    if len(i) < m: del d[i]
answer = sorted(d.keys(), key=lambda x:(-d[x], -len(x), x))
for i in answer: print(i)