n = int(input())
l = list(map(int, input().split()))
l.sort()
answer = 0
for i in range(len(l)): answer += sum(l[:i+1])
print(answer)