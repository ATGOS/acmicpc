import sys
n = int(input())
l = [0]*10000
for i in range(n) :
    a = int(sys.stdin.readline().rstrip())
    l[a-1] += 1

for i in range(10000) :
    if l[i] == 0 :
        pass
    else :
        for j in range(l[i]) :
            print(i+1)