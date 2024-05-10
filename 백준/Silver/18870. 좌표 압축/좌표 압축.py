import sys
input = sys.stdin.readline
n = int(input())
l = list(map(int, input().split()))
l2 = sorted(list(set(l)))
dict = {}
for i in range(len(l2)): dict[l2[i]] = i
for i in l: print(dict[int(i)], end = ' ')