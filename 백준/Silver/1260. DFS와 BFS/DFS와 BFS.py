# 1260

# 우선 2차원 배열에 정점 끼리의 연결 여부를 확인 한다.
# 또다른 1차원 배열에 정점의 방문 여부를 확인 한다.

from collections import deque
# n: 정점 개수, m: 간선 개수, v: 탐색 시작 번호
n, m, v = map(int, input().split())

l = [[0]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    l[a][b] = 1;l[b][a] = 1

# DFS
answer = []
current = v # 현재 정점 위치
visit = [0]*(n+1)   # 방문 하면 1
visit[v] = 1


def dfs(l, v, visit):
    visit[v] = 1
    answer.append(v)
    for k, i in enumerate(l[v][1:]):
        if not visit[k+1] and i == 1:
            dfs(l, k+1, visit)
dfs(l, v, visit)
print(*answer)

# BFS
d = deque([v])
answer = []
visit = [0]*(n+1)   # 방문 하면 1
while len(d) != 0:
    current = d.popleft()
    visit[current] = 1
    answer.append(current)
    for i in range(1, n+1):
        if l[current][i] == 1 and visit[i] != 1:
            d.append(i)
            visit[i] = 1
print(*answer)