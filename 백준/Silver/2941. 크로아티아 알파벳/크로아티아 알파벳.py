a = input()
res = len(a)
l = ['dz=', 'c-', 'c=', 'd-', 'lj', 'nj', 's=', 'z=']
for m in l :
    if m in a :
        if m == 'dz=' :
            res -= a.count(m) * 2
        else :
            res -= a.count(m)
        a = a.replace(m, ' ')
print(res)