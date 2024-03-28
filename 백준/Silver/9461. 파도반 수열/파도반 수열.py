a = int(input())
l = [1, 1, 1, 2, 2, 3, 4, 5, 7, 9]
for i in range(90) :
    l.append(l[9+i] + l[5+i])
for i in range(a) :
    b = int(input())
    print(l[b-1])