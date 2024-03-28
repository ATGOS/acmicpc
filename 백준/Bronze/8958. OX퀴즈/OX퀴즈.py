n = int(input())
for i in range(n):
    a = input()
    count = 0;streak = 1
    for j in a:
        if j == 'O':
            count+=streak
            streak+=1
        else:
            streak=1
    print(count)