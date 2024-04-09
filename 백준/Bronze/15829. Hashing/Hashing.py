n = input()
a = input()
s = 0
for k, i in enumerate(a):
    s+=((ord(i)-96) * (31**k))
print(s%1234567891)