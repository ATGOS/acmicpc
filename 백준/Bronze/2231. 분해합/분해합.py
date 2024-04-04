t = int(input())
for a in range(t//2, t+1):
    temp = a
    for i in str(a):
        temp += int(i)
    if temp == t:
        print(a)
        break
    elif a == t:
        print(0)
    a+=1