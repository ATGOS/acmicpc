import sys
aa, bb = map(int, input().split());c=0
a = set(map(int, sys.stdin.readline().rstrip().split()))
b = set(map(int, sys.stdin.readline().rstrip().split()))
print(len(b-a)+len(a-b))