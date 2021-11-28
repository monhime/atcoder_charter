n=int(input())
V=[int(_) for _ in input().split()]
C=[int(_) for _ in input().split()]
X_Y=[x-y for x,y in zip(V,C) if x-y>0]
print(sum(X_Y))