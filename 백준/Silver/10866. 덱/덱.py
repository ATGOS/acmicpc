from collections import deque
import sys
input = sys.stdin.readline
d = deque()
for i in range(int(input())):
    a = input()
    if a[:2]=='pu':
        if a[5]=='f': d.appendleft(int(a[11:]))
        else: d.append(int(a[10:]))
    elif a[:2]=='po':
        if not d: print(-1)
        else: print(d.popleft() if a[4]=='f' else d.pop())
    elif a[0]=='s':
        print(len(d))
    elif a[0]=='e':
        print(0 if d else 1)
    elif a[0]=='f':
        print(d[0] if d else -1)
    elif a[0]=='b':
        print(d[-1] if d else -1)