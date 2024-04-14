from collections import deque
import sys
input = sys.stdin.readline
n = int(input())
l = ['+']
d = deque([1])
temp = 2
for _ in range(n):
    a = int(input())
    while 1:
        if len(d) == 0 or d[-1] < a:
            d.append(temp)
            temp += 1
            l.append('+')
        elif d[-1] == a :
            d.pop()
            l.append('-')
            break
        else:
            l = ['NO']
            break
    if l[0] == 'NO': break
for i in l: print(i)