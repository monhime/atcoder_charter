n=input()
L=sorted(list(map(int,input().split())))
if sum(L[:-1])>L[-1]:print("Yes")
else:print("No")
