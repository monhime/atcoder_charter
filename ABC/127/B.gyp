r,d,x=map(int,input().split())
X=[x]
for i in range(10):
    X.append(r*X[-1]-d)
    print(X[-1])