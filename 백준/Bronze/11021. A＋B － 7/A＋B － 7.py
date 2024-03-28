import sys

a = int(input())
for i in range(a) :
    c, d = map(int, sys.stdin.readline().split())
    print(f"Case #{i+1}:", c+d)