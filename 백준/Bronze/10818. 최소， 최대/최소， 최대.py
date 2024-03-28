import sys
n = int(input())
l = list(map(int, sys.stdin.readline().split()))
print(min(l), max(l))