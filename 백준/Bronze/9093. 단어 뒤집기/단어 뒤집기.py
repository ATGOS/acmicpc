n = int(input())
for _ in range(n):
    l = input().split()
    for i in l: print(i[::-1], end = ' ')