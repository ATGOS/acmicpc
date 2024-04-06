import sys
input = sys.stdin.readline
n = int(input())
l = []
for i in range(n):
    a = input().split()
    a.insert(1, i)
    l.append(a)
l.sort(key=lambda x:(int(x[0]), x[1]))
for i in l:
    print(i[0], i[2])