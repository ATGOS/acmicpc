l = list(range(1,31))
for i in range(28) :
    l.remove(int(input()))
print(*l, sep='\n')