from collections import deque
n = int(input())
dq = deque(list(range(1, n+1)))
while 1:
    if len(dq) == 1:
         break
    dq.popleft()
    dq.append(dq.popleft())
print(*dq)