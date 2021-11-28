n=int(input())
W=[int(_) for _ in input().split()]
S_w=[W[0]]
for i in range(1,n):
    S_w.append(S_w[-1]+W[i])
ans=1000000
for i in range(n):
    ans=min(ans,abs(2*S_w[i]-S_w[n-1]))
print(ans)
