n,k=map(int,input().split())
bi=''
while n!=0:
    bi+=str(n%abs(k))
    if k<0:n=-(-n//k)
    else:n=n//k
print(len(bi))