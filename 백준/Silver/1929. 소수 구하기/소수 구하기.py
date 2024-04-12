M, N= map(int, input().split())
l = [1 for i in range(N+1)]
for i in range(2,int(N**0.5) + 1):
    if l[i]:
        j = 2
        while i*j <= N:
            l[i*j] = 0
            j += 1
l[1] = 0
for i in range(M, N+1):
    if l[i]:
        print(i)