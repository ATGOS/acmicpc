a = [];m = 0
for i in range(5) :
    s = input()
    a.append(s)
    if m < len(s) : m = len(s)
for i in range(m) :
    for j in range(5) :
        try : print(a[j][i], end = '')
        except : pass