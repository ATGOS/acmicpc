a, b = map(int, input().split())
c = int(input())
if((b + c) < 60) :
    print(a, b + c)
else :
    d = (b+c)//60
    e = (b+c)%60
    if((a + d) > 23) :
        print(a+d-24, e)
    else :
        print(a+d, e)