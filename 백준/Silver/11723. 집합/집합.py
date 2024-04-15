import sys
input = sys.stdin.readline
s = set()
m = int(input())
for i in range(m):
    a = input()
    if a[0:2] == 'ad': s.add(int(a[4:]))
    elif a[0] == 'r':
        if int(a[7:]) in s: s.remove(int(a[7:]))
    elif a[0] == 'c': print(1 if int(a[6:]) in s else 0)
    elif a[0] == 't':
        if int(a[7:]) in s: s.remove(int(a[7:]))
        else: s.add(int(a[7:]))
    elif a[0] == 'e': s = set()
    else: s = set(list(range(1, 21)))