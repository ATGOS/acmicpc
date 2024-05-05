import sys
sys.setrecursionlimit(10**6)
def dfs(l, visit, i, j):
    visit[i][j] = 1
    if l[i-1][j] == 1 and visit[i-1][j] == 0:        #한칸위
        dfs(l, visit, i-1, j)
    if l[i+1][j] == 1 and visit[i+1][j] == 0:       #한칸아래
        dfs(l, visit, i+1, j)
    if l[i][j-1] == 1 and visit[i][j-1] == 0:
        dfs(l, visit, i, j-1)
    if l[i][j+1] == 1 and visit[i][j+1] == 0:
        dfs(l, visit, i, j+1)


t = int(input())
for _ in range(t):
    answer = 0
    m, n, k = map(int, input().split())
    l = [[0]*(m+2) for _ in range(n+2)]
    visit = [[0]*(m+2) for _ in range(n+2)]
    for i in range(k):
        a, b = map(int, input().split())
        l[b+1][a+1] = 1
    for i in range(1, n+1):
        for j in range(1, m+1):
            if visit[i][j] == 0 and l[i][j] == 1:
                dfs(l, visit, i, j)
                answer+=1
    print(answer)