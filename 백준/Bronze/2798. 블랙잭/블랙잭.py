import itertools
n, m = map(int, input().split())
a = list(map(int, input().split()))
answ = 0
for i in itertools.combinations(a, 3):
    s = sum(i)
    if s <= m: answ = max(answ, s)
print(answ)