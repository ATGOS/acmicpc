n, m = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
left = 0;right = l[-1]
sum = 0
while left <= right:
    temp_sum = sum
    sum = 0
    middle = (left + right)//2
    for i in l: sum += ((i - middle) if i > middle else 0)
    if sum < m: right = middle - 1
    elif sum >= m : left = middle + 1
print(right)