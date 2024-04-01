import sys
input = sys.stdin.readline
n = int(input())
l = []
for i in range(n):
    l.append(list(map(int, input().rstrip().split())))
sorted_l = sorted(l, key = lambda x : (x, x))
for i in sorted_l:
    print(*i)