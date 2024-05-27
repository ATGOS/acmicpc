import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
x = [0, 0, 1, -1]
y = [1, -1, 0, 0]

def dfs(n1, m1, x, y):
    if l[n1][m1] == 'X':  
        return
    elif l[n1][m1] == 'P': 
        global answer
        answer += 1
    l[n1][m1] = 'X'
    for j in range(4):
        dfs(n1 + x[j], m1 + y[j], x, y)

answer = 0
n, m = map(int, input().split())
l = []
l.append(list('X'*(m+2)))
for i in range(n):
    a = input().rstrip()
    a = 'X' + a + 'X'
    l.append(list(a))
    if 'I' in l[-1]:
        temp_n = i + 1; temp_m = l[-1].index('I')
l.append(list('X'*(m+2)))
dfs(temp_n, temp_m, x, y)
print('TT' if answer == 0 else answer)