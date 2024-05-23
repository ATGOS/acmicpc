n = int(input())
l = [0]
dp = [0] * 301
for i in range(n):
    l.append(int(input()))
if n == 1:
    print(l[-1])
else:
    dp[1] = l[1]
    dp[2] = l[1] + l[2]
    for i in range(3, n+1):
        dp[i] = l[i] + max(dp[i-3] + l[i-1], dp[i-2])
    print(dp[n])