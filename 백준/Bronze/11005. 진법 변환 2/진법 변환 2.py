N, B = map(int, input().split())
c=[]
while 1 :
    if N == 0 :
        break
    if N%B > 9 :
        c.append(chr(N%B+55))
    else :
        c.append(N%B)
    N //= B
print(*c[::-1], sep='')