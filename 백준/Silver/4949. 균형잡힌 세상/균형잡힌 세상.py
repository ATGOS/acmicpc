while 1:
    a = input()
    if a == '.': break
    l = []
    for i in a:
        if i == '(' or i == ')' or i == '[' or i == ']':
            l += i
    while 1:
        k = ''.join(l)
        if '()' in k:
            del l[k.index('()'):k.index('()') + 2]
        elif '[]' in k:
            del l[k.index('[]'):k.index('[]') + 2]
        else:
            if len(l) == 0:
                print('yes')
                break
            else:
                print('no')
                break
