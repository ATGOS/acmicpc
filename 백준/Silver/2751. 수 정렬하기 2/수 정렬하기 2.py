import sys
a = input()
b = []
for i in range(int(a)) :
    b.append(int(sys.stdin.readline().rstrip()))
b.sort()
for i in range(int(a)) :
    print(b[i])