n = int(input())
l = []
for i in range(n):
    l.append(list(map(int, input().split())))
for i in l:
    answer=1
    for j in l:
        if i[0] < j[0] and i[1] < j[1]:
            answer+=1
    print(answer)