n = int(input())
a = list(map(int, input().split()))
p = [-1] * n
l = []

l.append(0)
for i in range(n-1):
    while len(l) != 0 and a[l[-1]] < a[i+1]:
        p[l.pop()] = a[i+1]
    l.append(i+1)
print(*p)