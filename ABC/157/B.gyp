A=[[int(_) for _ in input().split()] for i in range(3)]
flag=[[0]*3 for i in range(3)]
n=int(input())
for k in range(n):
    b = int(input())
    for i in range(3):
        for j in range(3):
            if A[i][j]==b:
                flag[i][j]=1
import numpy as np
if (3 in np.sum(flag,axis=0)) or (3 in np.sum(flag,axis=1)) or (((flag[0][0]==flag[1][1] and flag[1][1]==flag[2][2]) or (flag[0][2]==flag[1][1] and flag[1][1]==flag[2][0])) and flag[1][1]==1):
    print("Yes")
else:
    print("No")