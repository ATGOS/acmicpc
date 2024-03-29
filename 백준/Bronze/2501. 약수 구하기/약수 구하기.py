p, q = map(int, input().split())
l = []
for i in range(1, int(p**1/2)+2):
    if p%i == 0:
        l.append(i)
        l.append(p//i)
l = list(set(l))
l.sort()
if len(l) < q: print(0)
else: print(l[q-1])