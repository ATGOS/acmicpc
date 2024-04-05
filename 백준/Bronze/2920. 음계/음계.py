a = list(map(int, input().split()))
temp = 0
if sorted(a) == a:
    print('ascending')
elif sorted(a, reverse=True) == a:
    print('descending')
else:
    print('mixed')