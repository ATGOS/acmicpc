import sys
s = set();l = [[] for i in range(50)]
n = int(input())
for i in range(n) :
    a = sys.stdin.readline().rstrip()
    l[len(a)-1].append(a)
for i in range(50) :
    l[i] = set(l[i])
    l[i] = list(l[i])
    l[i].sort()
    if len(l[i]) != 0 : print(*l[i], sep='\n')