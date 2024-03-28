b = list(input())
for i in range(26) :
    try :
        print(b.index(chr(i+97)))
    except :
        print(-1)