n, k = map(int, input().split())
l = []
for _ in range(n):
    l.append(int(input()))
answer = k%l[1] if len(l)!=1 else k
k -= answer
for i in l[::-1]:
    if k//i>0:
        answer += k//i
        k-=i*(k//i)
print(answer)