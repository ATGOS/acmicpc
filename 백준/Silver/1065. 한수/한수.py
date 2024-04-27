n = int(input())
if n<10: print(n)
else:
    summ = 9
    for i in range(10, n+1):
        temp = int(str(i)[1]) - int(str(i)[0])
        for j in range(len(str(i))-1):
            if int(str(i)[j+1]) - int(str(i)[j]) != temp: break
        else: summ+=1
    print(summ)