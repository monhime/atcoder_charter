n,d=map(int,input().split())
X=[[int(_) for _ in input().split()] for i in range(n)]
sqr_list=[]
for i in range(130):
    sqr_list.append(i**2)
count=0
for i in range(n-1):
    for j in range(i+1,n):
        sum=0
        for k in range(d):
            sum+=(X[i][k]-X[j][k])**2
        if sum in sqr_list:
            count+=1
print(count)