l = [0]*10036
for i in range(1, 10001):
    k = i
    for j in str(i):
        k+=int(j)
    l[k] += 1
for i in range(1, 10001):
    if l[i] == 0:
        print(i)