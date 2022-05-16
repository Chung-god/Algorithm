def fac(n):
    if n==1:
        return 1
    return n*fac(n-1)

N = int(input())
if N == 0:
    print(0)
else: 
    n=list(reversed(str(fac(N)))) 
    for i in n:
        print(n)
        if i!='0':
            print(n.index(i))
            break
