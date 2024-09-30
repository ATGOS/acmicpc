ans = 0
t = int(input())
for a in range(t//2, t+1):
    temp = sum((map(int, str(a)))) + a
    if temp == t:
        ans = a
        break
print(ans)