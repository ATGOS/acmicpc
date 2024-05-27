x, y, w, s = map(int, input().split())
if w > s: 
    if abs(x-y)%2: print((abs(x-y)-1)*s + (min(x, y)*s) + w)
    else: print(abs(x-y)*s + min(x, y)*s)
elif 2*w > s: print(abs(x-y)*w + min(x, y)*s)
else: print((x+y)*w)