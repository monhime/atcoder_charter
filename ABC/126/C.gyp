import math
n,k=map(int,input().split())
s=0
for i in range(1,n+1):
    if i<k:
        s+=0.5**(-(-math.log(k/i,2)//1))
    else:
        s+=1
print(s/n)