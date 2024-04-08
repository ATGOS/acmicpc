from collections import deque
n, k = map(int, input().split())
d = deque(i+1 for i in range(n))
l = []
while d:
    d.rotate(1-k)
    l.append(d.popleft())
print('<', end = '')
print(*l, end = '', sep = ', ')
print('>')