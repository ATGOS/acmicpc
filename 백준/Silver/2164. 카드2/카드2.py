from collections import deque
n = int(input())
dq = deque(i+1 for i in range(n))
if len(dq) == 1: print(*dq)
else:
    while 1:
        dq.popleft()
        if len(dq) == 1:
            break
        dq.append(dq.popleft())
    print(*dq)