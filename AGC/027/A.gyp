n,x=map(int,input().split())
A=sorted(list(map(int,input().split())))
for i in range(n):
    x-=A[i]
    if x<0:break
else:
    if x==0:i+=1
print(i)


    