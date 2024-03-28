m = int(input())
for i in range(m) :
    a, b = map(int, input().split())
    k = int(str(a)[-1])**(b%4+4)
    if a%10 == 0 : print(10)
    else : print(k%10)