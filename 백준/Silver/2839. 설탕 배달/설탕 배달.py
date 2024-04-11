n = int(input())
three = 0;five = n//5;
while 1:
    if three*3 + five*5 == n:
        print(five+three)
        break
    elif three*3 + five*5 > n:
        if five > 0:
            five-=1
        else:
            print(-1)
            break
    elif three*3 + five*5 < n:
        three += 1
    elif 3*(three + 1) > n:
        print(-1)
        break