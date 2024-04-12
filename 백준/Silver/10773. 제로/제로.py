k = int(input())
l = []
for _ in range(k):
    a = int(input())
    if a == 0: l.pop()
    else: l.append(a)
print(sum(l))