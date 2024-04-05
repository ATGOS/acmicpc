t = int(input())

def recursion(strr, i, j):
    global count
    count += 1
    if i >= j:
        return 0
    if strr[i] == strr[j]:
        recursion(strr, i+1, j-1)
    else:
        return 0

for i in range(t):
    a = input()
    count = 0
    recursion(a, 0, len(a)-1)
    if a == a[::-1]:
        isPalindrome = 1
    else:
        isPalindrome = 0
    print(isPalindrome, count)