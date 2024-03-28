c=0;m=100
for i in range(7) :
    a = int(input())
    if a%2==1:
        c+=a
        if a < m:
            m = a
if m==100: print(-1)
else: print(c, m, sep='\n')