k, n = map(int, input().split())
l = []
for _ in range(k):
    l.append(int(input()))
l.sort()
left = 1; right = l[-1]
while left <= right:
    sum = 0
    middle = (left + right)//2
    for i in l:
        sum += (i//middle)
    if sum < n:
        right = middle - 1
    elif sum >= n:
        left = middle + 1
print(left-1)