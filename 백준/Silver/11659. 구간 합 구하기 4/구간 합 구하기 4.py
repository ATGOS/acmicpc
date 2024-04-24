import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = list(map(int, input().split()))
summ = 0
l = [0]
for i in a:
    summ+=i
    l.append(summ)
for _ in range(m):
    i, j = map(int, input().split())
    print(l[j]-l[i-1])