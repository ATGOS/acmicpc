n = int(input())
t = 0;l = []
for i in range(n):
    l.append(int(input()))
l.sort(reverse=True)
for i in range(n):
    if l[i] > i:
        t+=(l[i]-i)
print(t)