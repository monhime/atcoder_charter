n=int(input())
A=[int(_) for _ in input().split()]
B=[int(_) for _ in input().split()]
C=[int(_) for _ in input().split()]
ans=sum(B)
for i in range(n-1):
    if A[i+1]==A[i]+1:
        ans+=C[A[i]-1]

print(ans)