n, m = map(int, input().split())
l = {}
for _ in range(n):
    a, b = input().split()
    l[a] = b
for _ in range(m): print(l[input()])