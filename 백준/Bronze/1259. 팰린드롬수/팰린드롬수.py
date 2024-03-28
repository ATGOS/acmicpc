while True :
    a = input()
    b = len(a)
    c = 0
    if a == '0' : break
    for i in range(b//2) :
        if a[i] != a[b-i-1] :
            print("no")
            c+=1
            break
    if c == 0 : print("yes")