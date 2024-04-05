t = int(input())
for i in range(t):
    h, w, n = map(int, input().split())
    floor = n%h if n%h != 0 else h
    addr = n//h+1 if n//h != n/h else n//h
    print(f'{floor}{addr:02d}')