a,b,k=map(int,input().split())
if k<=a:print(a-k,b)
elif k-a<=b:print(0,b-k+a)
else:print(0,0)