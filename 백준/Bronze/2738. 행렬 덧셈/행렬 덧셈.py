num1, num2 = map(int, input().split())#num1 : 행, num2: 열
A = []
B = []
for i in range(num1):
    A.append(input().split())
for i in range(num1):
    B.append(input().split())
for i in range(num1):
    for j in range(num2):
        A[i][j] = int(A[i][j]) + int(B[i][j])
    print(*A[i])