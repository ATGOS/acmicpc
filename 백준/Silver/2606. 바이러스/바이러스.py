c = int(input())
line = int(input())
l = [[] for i in range(c+1)]
for i in range(line):
    a, b = map(int, input().split())
    l[a].append(b);l[b].append(a)
visit = [0] * (c+1)
def search(l, n):
    visit[n] = 1
    for i in l[n]:
        if not visit[i]:
            search(l, i)

search(l, 1)
print(sum(visit)-1)