t = int(input())
for i in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    count=0
    for j in range(n):
        cx, cy, r = map(int, input().split())
        a = (cx-x1)**2 + (cy-y1)**2 < r**2
        b = (cx-x2)**2 + (cy-y2)**2 < r**2
        if (not a and b) or (a and not b):
            count+=1
    print(count)