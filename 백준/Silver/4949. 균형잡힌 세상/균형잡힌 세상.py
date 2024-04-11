import sys
input = sys.stdin.readline
while 1:
    a = input().rstrip()
    if a == '.': break
    l = []
    for i in a:
        if i == '(' or i == ')' or i == '[' or i == ']': l += i
    while 1:
        k = ''.join(l)
        if '()' in k: del l[k.index('()'):k.index('()') + 2]
        elif '[]' in k: del l[k.index('[]'):k.index('[]') + 2]
        else:
            print('yes' if len(l) == 0 else 'no')
            break