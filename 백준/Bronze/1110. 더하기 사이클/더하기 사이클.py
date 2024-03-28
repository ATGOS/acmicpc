n = input();c = 0;p = 0
if len(n) == 1 : n = '0' + n
nn = n
while 1 :
    t = int(nn[0]) + int(nn[1])
    p = nn[-1] + str(t)[-1]
    nn = p
    c+=1
    if p == n : break
print(c)
