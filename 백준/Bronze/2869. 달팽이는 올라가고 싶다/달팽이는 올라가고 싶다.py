a, b, v = map(int, input().split())
#낮에+A 밤에-B 높이는V
h = 0;d = 0
if v<a:
    print(1)
else:
    d+=((v-a)//(a-b))
    v -= (a-b)*d
    while 1:
        v-=a;d+=1
        if v <= 0:
            break
print(d)