n,m=map(int,input().split())
M=[0]*31
for i in range(n):
    a=[int(_) for _ in input().split()]
    for j in range(a[0]):
        M[a[j+1]]+=1

print(M.count(n))