n, m = map(int, input().split())
a=[];b=[]
for i in range(n) :
    a.append(list(map(int, input().split())))
for i in range(n) :
    b.append(list(map(int, input().split())))
    for j in range(m) :
        b[i][j]+=a[i][j]
for i in b :
    print(*i)