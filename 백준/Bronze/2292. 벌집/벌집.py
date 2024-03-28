n = int(input())
r=0
if n == 1:
    print(1)
else:
    n-=1
    while n>0:
        r+=1;n-=(r*6)
    print(r+1)