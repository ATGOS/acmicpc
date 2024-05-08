# 1016
# 1_000_001 까지의 소수를 모두 구한 뒤 제곱해서 나눠봄
min1, max1 = map(int, input().split())
r = 1_000_002
l1 = [1]*r  # 소수이면 1 아니면 0
l2 = []     # 1_000_001 까지의 소수만 모아 놓음
for i in range(2, r):
    if l1[i]:
        l2.append(i)
        j = 2
        while i*j < r:
            l1[i*j] = 0 # 소수가 아니므로 0
            j += 1
answer = max1 - min1 + 1
l1 = [1] * answer
for i in l2:
    i *= i
    n = (min1//i)*i
    while n <= max1:
        if min1 <= n: l1[n-min1] = 0
        n += i
print(sum(l1))