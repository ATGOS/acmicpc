a = int(input())
b = list()
c = []
for i in range(a) :
    b.append(list(map(int, input().split())))
    c.append(0)
for k in range(a) :
    for i in range(a) :
        for j in range(5) :
            if b[i][j] == b[k][j] :
                c[k] += 1
                break
print(c.index(max(c))+1)