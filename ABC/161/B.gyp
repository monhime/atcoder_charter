n,m=map(int,input().split())
A=[int(_) for _ in input().split()]
sum_a=sum(A)
A_x=[a for a in A if a>=sum_a/(4*m)]
if m<= len(A_x):print("Yes")
else:print("No")