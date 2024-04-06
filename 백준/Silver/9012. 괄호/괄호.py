t = int(input())
for i in range(t):
    a = input()
    if a.count('(') != a.count(')'):
        print('NO')
        continue
    left = 0; right = 0
    for j in a:
        if j == '(': left += 1
        else: right += 1
        if left < right:
            print('NO')
            break
    if left == right: print('YES')