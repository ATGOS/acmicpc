n = int(input())
l = []
for i in range(n):
    l.append(list(map(int, input().split())))
sorted_l = sorted(l, key = lambda x : (x, x))
for i in sorted_l:
    print(*i)