N = int(input())
c = 1
count = 0
for i in range(N):
    c*=(i+1)
for i in str(c)[::-1]:
    if i != '0':
        break
    count+=1
print(count)