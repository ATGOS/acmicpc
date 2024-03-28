a = int(input())
for i in range(a):
    l = [[1, 0], [0, 1]]
    n = int(input())
    for i in range(n-1):
        l.append([l[i][0]+l[i+1][0], l[i][1]+l[i+1][1]])
    print(*l[n])