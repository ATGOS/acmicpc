import sys
input = sys.stdin.readline
n = int(input())
l = []
d = {}
user = set()
lower = 0
keys = d.keys()
for i in range(n):
    l.append(list(input().split())[1:3])
    if l[-1][0] in user or l[-1][0] == 'megalusion': continue
    if l[-1][0] not in keys: d[l[-1][0]] = 1
    else: d[l[-1][0]] += 1
    if l[-1][1] == '4':
        user.add(l[-1][0])
        lower += d[l[-1][0]]

if lower == 0 and len(user) == 0: print(0)
else: print((len(user)/(lower))*100)
