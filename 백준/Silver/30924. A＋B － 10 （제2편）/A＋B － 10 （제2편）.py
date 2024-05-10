import random

l = [i for i in range(1, 10001)]
l2 = l[:]
random.shuffle(l)
random.shuffle(l2)
while 1:
    A = l.pop()
    print("? A", A)
    if int(input()): break
while 1:
    B = l2.pop()
    print("? B", B)
    if int(input()): break
print("!", A+B)