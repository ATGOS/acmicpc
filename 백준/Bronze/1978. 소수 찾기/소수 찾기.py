a = 0
n = int(input())
l = list(map(int, input().split()))
for i in l:
    c = 0
    for j in range(2, int(i**0.5)+1):
        if i%j == 0:
            c+=1
    if c == 0:
        a+=1
print(a-l.count(1))