h,w=map(int,input().split())
A=[input() for i in range(h)]
count=0
for i in range(h):
    for j in range(w):
        if A[i][j]=='#':
            count+=1
if count==h+w-1:
    print("Possible")
else:print("Impossible")