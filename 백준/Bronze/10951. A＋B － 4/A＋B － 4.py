import sys
while True:
    a = list(map(int, sys.stdin.readline().split()))
    if not a: break
    print(sum(a))