a = 1; b = 4;c = 1; result = 4
n = int(input())
for i in range(n):
    result += (a*b+c)
    a*=2
    b+=a
    c*=4
print(result)