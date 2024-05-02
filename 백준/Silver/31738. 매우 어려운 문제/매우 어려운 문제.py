n, m = map(int, input().split())

summ = 1
if n >= m: 
    print(0)
else:
    for i in range(2, n+1):
        summ = (summ * i) % m
    print(summ%m)