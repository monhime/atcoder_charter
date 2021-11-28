n,t=map(int,input().split())
X=[[int(_) for _ in input().split()] for i in range(n)]
X=[x for x in X if x[1]<=t]
if len(X)==0:print("TLE") 
else:
    X.sort()
    print(X[0][0])
