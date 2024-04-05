import sys
input = sys.stdin.readline
n = int(input())
lst1 = list(map(int, input().rstrip().split()))
lst1.sort()
m = int(input())
lst2 = list(map(int, input().rstrip().split()))

start = 0; end = len(lst1) - 1 #이분탐색

for i in lst2:
    start = 0
    end = len(lst1) - 1
    while 1:
        half = (start + end)//2
        #print(start, end, half)
        if lst1[half] > i: # 이분탐색의 왼쪽
            end = half
        elif lst1[half] < i: # 이분탐색의 오른쪽
            if half == start:
                half+=1
            start = half
        if lst1[half] == i:
            print(1)
            break
        if end <= start:
            print(0)
            break