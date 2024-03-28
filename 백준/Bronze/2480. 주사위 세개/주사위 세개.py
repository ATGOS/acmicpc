a, b, c = map(int, input().split())
if a==b==c :
    print(10000+a*1000)
elif (a!=b)&(b!=c)&(c!=a) :
    print(max(a, b, c)*100)
else :
    l = [a, b, c]
    l.sort()
    print(1000+l[1]*100)