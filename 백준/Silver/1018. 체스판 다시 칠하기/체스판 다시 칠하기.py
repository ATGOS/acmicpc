m, n = map(int, input().split())
m1 = m - 7;n1 = n - 7
k = list()
for i in range(m) : # B = 0, W = 1
    a = input()
    k.append(a)
def chess(m2, n2, worb) :
    c = 0
    for i in range(4) :
        for j, clr in enumerate(worb) :
            if k[2*i+m2][j+n2] != clr :
                c += 1
    return(c)
min_ = 64
for i in range(m1) :
    for j in range(n1) :
        min_ = min(chess(i, j, 'WBWBWBWB')+chess(i+1, j, 'BWBWBWBW'), chess(i, j, 'BWBWBWBW')+chess(i+1, j, 'WBWBWBWB'), min_)
print(min_)