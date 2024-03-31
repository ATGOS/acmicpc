import sys
input = sys.stdin.readline
n = int(input())
s = []
for i in range(n):
    a = input().rstrip()
    if a[:4] == 'push':
        s.append(int(a[5:]))
    if a == 'pop':
        if s: print(s.pop())
        else: print(-1)
    elif a == 'size':
        print(len(s))
    elif a == 'empty':
        if s: print(0)
        else: print(1)
    elif a == 'top':
        if s: print(s[-1])
        else: print(-1)