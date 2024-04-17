import sys
input = lambda : sys.stdin.readline()
n, m = map(int, input().split())
d = {}
for _ in range(n):
    d[input().rstrip()] = 1
l = [];answer = 0
for _ in range(m):
    a = input().rstrip()
    try:
        if d[a] == 1:
            l.append(a)
            answer += 1
    except: pass
print(answer)
for i in sorted(l): print(i)