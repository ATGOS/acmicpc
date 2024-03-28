n, m = map(int, input().split())
l=[];p=[]
for i in range(3*n):
    l.append(input())
    if i%3==1:
        for j in range(m): #c가 한글자일때 맞으면1 틀리면0   c가 두글자일때 맞으면2 틀리면0
            try:
                if int(l[i][8*j+1]) + int(l[i][8*j+3]) == int(l[i][8*j+5:8*j+7]):
                    p.append(2)
                else:
                    p.append(0)
            except:
                if int(l[i][8*j+1]) + int(l[i][8*j+3]) == int(l[i][8*j+5]):
                    p.append(1)
                else:
                    p.append(0)
for i in range(n):
        for j in range(m):
            if p[m*i+j]==1:
                print('.*****..', end='')
            elif p[m*i+j]==2:
                print('.******.', end='')
            else:
                print('.../....', end = '')
        print()
        for j in range(m):
            if p[m*i+j]==1:
                print('*',l[3*i+1][8*j+1:8*j+6], '*.', sep='', end='')
            elif p[m*i+j]==2:
                print('*', l[3*i+1][8*j+1:8*j+7], '*', sep='', end='')
            else:
                print(l[3*i+1][8*j:8*j+2], '/', l[3*i+1][8*j+3:8*j+8] ,sep='', end='')
        print()
        for j in range(m):
            if p[m*i+j]==1:
                print('.*****..', end='')
            elif p[m*i+j]==2:
                print('.******.', end='')
            else:
                print('./......', end='')
        print()