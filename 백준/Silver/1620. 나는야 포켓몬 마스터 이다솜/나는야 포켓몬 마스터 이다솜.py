import sys
input = sys.stdin.readline
n, m = map(int, input().rstrip().split())
d1 = {}
for i in range(n):
    a = input().rstrip()
    d1[a] = i+1
k = list(d1.keys())
for _ in range(m):
    b = input().rstrip()
    try:
        print(k[int(b)-1])
    except:
        print(d1[b])