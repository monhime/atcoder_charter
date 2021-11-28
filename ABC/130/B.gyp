n,x=map(int,input().split())
L=[int(_) for _ in input().split()]
S_L=[0]
count=1
for i in range(n):
    S_L.append(S_L[-1]+L[i])
    if S_L[-1]<=x:
        count+=1
    else:
        print(count)
        break
else:print(n+1)