t = int(input())
for _ in range(t):
    k = int(input())
    n = int(input())
    l = [[1]*(k+1)]
    for i in range(n-1):
        temp_l = [i+2]
        for j in range(k): temp_l.append(temp_l[-1] + l[-1][j+1])
        l.append(temp_l)
    print(l[-1][-1])