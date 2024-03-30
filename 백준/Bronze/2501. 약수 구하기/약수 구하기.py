p, q = map(int, input().split())
l = []
for i in range(1, p+1):
    if p%i == 0:
        l.append(i)
if len(l) < q: print(0)
else: print(l[q-1])