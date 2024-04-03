a = input()
l = []
for i in range(len(a)):
    l.append(a[i:])
for i in sorted(l):
    print(i)