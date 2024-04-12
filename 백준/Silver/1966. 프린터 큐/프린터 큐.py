from collections import deque
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    l = deque([i] for i in range(n))
    l2 = list(map(int, input().split()))
    for i in range(n):
        l[i].append(l2[i])
    l2.sort()
    answer = 0
    while 1:
        if l[0][1] == l2[-1]:
            if l[0][0] == m:
                print(answer + 1)
                break
            else:
                l.popleft()
                answer += 1
                l2.pop()
        else:
            l.append(l.popleft())