n,k,m=map(int,input().split())
A=[int(_) for _ in input().split()]
a_sum=sum(A)
if m*n-a_sum>k:print(-1)
else:print(m*n-a_sum)