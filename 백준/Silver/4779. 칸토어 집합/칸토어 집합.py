def cantor(a):
    if a == 0:
        return '-'
    else:
        return cantor(a-1) + ' '*(3**(a-1)) + cantor(a-1)
while 1:
    try:
        n = int(input())
        print(cantor(n))
    except:
        break