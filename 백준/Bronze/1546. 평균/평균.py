m = int(input())
l = list(map(int, input().split()))
x = max(l);p = 0
for i in range(len(l)) :
    l[i] = l[i]/x * 100
    p+=l[i]
print(p/m)