from collections import Counter
n = int(input())
n_l = list(map(int, input().split()))
m = int(input())
m_l = list(map(int, input().split()))
c = Counter(n_l)
for i in m_l:
    if i in c: print(c[i], end = ' ')
    else: print(0, end = ' ')