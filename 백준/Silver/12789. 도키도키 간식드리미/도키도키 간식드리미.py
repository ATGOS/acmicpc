n = int(input())
l = list(map(int, input().split()))
l1 = [0]
l2 = [n+1]
s = 0
while len(l1) != n+1:
    if l[s] - l1[-1] == 1:
        l1.append(l[s])
        s+=1
        while len(l2) != 1:
            if l2[-1] - l1[-1] == 1:
                l1.append(l2.pop())
            else:
                break
    elif l2[-1] > l[s]:
        l2.append(l[s])
        s+=1
    else:
        print('Sad')
        break
    #print(l1, l2)
else:
    print('Nice')