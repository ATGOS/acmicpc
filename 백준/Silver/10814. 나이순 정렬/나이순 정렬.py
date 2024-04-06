import sys
input = sys.stdin.readline
n = int(input())
l = []
for i in range(n):
    l.append(input().split() + [i])
l.sort(key=lambda x:(int(x[0]), x[2]))
for i in l:
    print(i[0], i[1])