import sys
input = sys.stdin.readline
m = 1e-9
n = int(input())
l = []
for i in range(n):
    l.append(int(input()))
l.sort()
trim = round((n*15)/100+m)
if n == 0: d = 0
else:
    d = round(sum(l[trim:n - trim]) / (n - 2 * trim) + m)
print(d)