from bisect import bisect_left, bisect_right
n = int(input())
n_l = list(map(int, input().split()))
m = int(input())
m_l = list(map(int, input().split()))
n_l.sort()
for i in m_l:
    print(bisect_right(n_l, i) - bisect_left(n_l, i), end = ' ')
