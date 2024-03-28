arr = []
for i in range(9) :
    arr.append(list(map(int, input().split())))
m = 0;ii = 1;jj = 1
for a, i in enumerate(arr) :
    for b, j in enumerate(i) :
        if m < j :
            ii = a + 1
            jj = b + 1
            m = j
print(m)
print(ii, jj)