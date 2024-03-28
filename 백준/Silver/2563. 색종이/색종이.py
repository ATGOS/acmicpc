p = int(input());one = '1111111111';c=0
l = [['0' for _ in range(100)] for __ in range(100)]
for i in range(p) :
    x, y = map(int, input().split())
    for j in range(10) :
        l[y+j][x:x+10] = one
for i in range(100) :
    c+=l[i].count('1')
print(c)