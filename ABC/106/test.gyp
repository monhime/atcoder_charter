n=65
k=3 #負でも可能
bi=''
while n!=0:
    bi+=str(n%abs(k))
    if k<0:n=-(-n//k)
    else:n=n//k
print(bi[::-1])
