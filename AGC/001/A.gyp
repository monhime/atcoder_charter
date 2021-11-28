n=int(input())
L=sorted(list(map(int,input().split())))
ans=0
for i in range(n):
    ans+=L[2*i]
print(ans)
