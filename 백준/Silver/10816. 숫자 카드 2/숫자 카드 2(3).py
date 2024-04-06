n = int(input())
d = {}
n_l = list(map(int, input().split()))
m = int(input())
m_l = list(map(int, input().split()))
for i in n_l:
    if i in d: d[i] += 1
    else: d[i] = 1
for i in m_l:
    if i in d: print(d[i], end = ' ')
    else: print(0, end = ' ')
