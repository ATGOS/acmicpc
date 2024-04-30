n = int(input())
l = list(map(int, input().split()))
l1 = [0]
l2 = [n+1]
s = 0

for i in l:
    if i - l1[-1] == 1:
        l1.append(i)
        while len(l2) != 1:
            if l2[-1] - l1[-1] == 1: l1.append(l2.pop())
            else: break
    elif l2[-1] > i: l2.append(i)
    else:
        print('Sad')
        break
else: print('Nice')