import sys
input = sys.stdin.readline
n = int(input())
l = [0] * 1001
answer = 0
for i in range(n):
    a, b = input().split()
    if a == 'jinju': d = int(b)
    else:
        if int(b) > 1000: answer += 1
        else: l[int(b)] += 1
print(d)
print(sum(l[d+1:])+answer)