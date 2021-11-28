n,m,c=map(int,input().split())
B=[int(_) for _ in input().split()]
count=0
for i in range(n):
    A=[int(_) for _ in input().split()]
    D=c
    for j in range(m):
        D+=A[j]*B[j]
    if D>0:
        count+=1
print(count)