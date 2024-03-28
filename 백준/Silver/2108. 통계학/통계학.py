import sys
n = int(input());l = [];s = 0;l2=[0]*8001
for i in range(n) :
    c = int(sys.stdin.readline().rstrip())
    l.append(c)
    l2[c+4000]+=1
    s+=c
mmax = 0;m = 0;l1=[]
for i in l2 :
    if i == mmax :
        m+=1;mmax = i
        l1.append(l2.index(i))
        l2[l2.index(i)] = 0
    elif i > mmax :
        m = 1;l1 = [l2.index(i)];mmax = i;l2[l2.index(i)]=0
l.sort()
if m==1 : a = int(*l1)
else: a = l1[1]
print(round(s/n), l[(n-1)//2], a-4000, max(l)-min(l), sep='\n')