t = int(input())
for i in range(t):
    a = int(input())
    print(a//25, end=' ')
    a%=25
    print(a//10, end=' ')
    a%=10
    print(a//5, end=' ')
    print(a%5)