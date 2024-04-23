n = int(input())
l = []
for _ in range(n):
    l.append(int(input()))
l.sort(reverse=True)
sub = 0
for i in range(len(l)//3):
    sub += min(l[3*i:3*i+3])
print(sum(l)-sub)