l = list(input().upper())
k = [0]*26
for i in l :
    k[ord(i)-65] += 1
c=0;d=max(k)
for i in range(26) :
    if max(k) == k[i] : c+=1
if c > 1 : print('?')
else : print(chr(k.index(max(k))+65))