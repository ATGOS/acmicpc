t = int(input())
d = [0, 1, 2, 4] + [0]*(7)
for i in range(4, 11): d[i]=d[i-1]+d[i-2]+d[i-3]
for i in range(t):
    n = int(input())
    print(d[n])