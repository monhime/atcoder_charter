n,p=map(int,input().split())
A=[int(a)%2 for a in input().split()]
odd=sum(A)
if odd==0:
    if p==1:print(0)
    else:print(2**n)
else:print(2**(n-1))