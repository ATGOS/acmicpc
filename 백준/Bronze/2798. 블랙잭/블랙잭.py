import itertools
n, m = map(int, input().split())
a = list(map(int, input().split()))
answ = 0
c = itertools.combinations(a, 3)
for i in c:
    s = sum(i)
    if s <= m:
        answ = max(answ, s)
print(answ)