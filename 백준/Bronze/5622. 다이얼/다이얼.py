m = input();n=0
s = [3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10]
for i in m:
    n += s[ord(i)-ord('A')]
print(n)