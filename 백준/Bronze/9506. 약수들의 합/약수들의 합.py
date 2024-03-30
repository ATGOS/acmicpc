while 1:
    a = int(input())
    if a == -1:
        break
    l=[];c=0
    for i in range(1, a):
        if a%i == 0:
            l.append(i)
            c+=i
    if a == c:
        print(f'{a} =', end = '')
        for i, j in enumerate(l):
            if i == len(l) - 1:
                print(f' {j}')
            else:
                print(f' {j} +', end = '')
    else:
        print(f'{a} is NOT perfect.')