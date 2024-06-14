n = int(input())
S, M, L, XL, XXL, XXXL = map(int, input().split())
T, P = map(int, input().split())

print((S-1)//T + (M-1)//T + (L-1)//T + (XL-1)//T + (XXL-1)//T + (XXXL-1)//T + 6)
print(n//P, n - P*(n//P))