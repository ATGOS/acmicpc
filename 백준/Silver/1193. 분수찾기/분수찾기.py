c = 0
x = int(input())
while 1:
    c+=1
    if x <= c:
        break
    x-=c
c+=1
if (c-1)%2 == 0:
    print(x, '/',c-x, sep='')
else:
    print(c-x, '/', x, sep='')