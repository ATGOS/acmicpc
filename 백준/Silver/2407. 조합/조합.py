def fac(a) :
    res = 1
    for i in range(a) :
        res *= i + 1
    return res
c, d = map(int, input().split())
RE = fac(c) // (fac(c - d) * fac(d))
print(RE)