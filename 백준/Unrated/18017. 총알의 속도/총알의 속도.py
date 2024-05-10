import decimal
c = 299_792_458
a, b = map(decimal.Decimal, input().split())
print((a+b)/(1+(a*b)/(c*c)))