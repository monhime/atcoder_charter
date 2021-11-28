n=int(input())
X=[]
for i in range(n):
    s,p=input().split()
    X.append((s,100-int(p),i+1))
X=sorted(X,key=lambda x:(x[0],x[1]))
for i in range(n):
    print(X[i][2])