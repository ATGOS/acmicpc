import sys
input = sys.stdin.readline
n = int(input())
l = []
for i in range(n):
    l.append(tuple(input().split()))
    if l[-1][0] == 'jinju': a = int(l[-1][1])
b = 0
for i in l: 
    if int(i[1]) > a: b+=1
print(a)
print(b)