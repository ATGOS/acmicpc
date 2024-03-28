n = int(input());d=0
for i in range(n) :
    a = [0 for _ in range(26)]
    c = 0
    b = input()
    for p, j in enumerate(b) :
        if a[ord(j)-97] != 0 and b[p-1] != j :
            break
        a[ord(j)-97] += 1
        c+=1
    if c == len(b) : d +=1
print(d)