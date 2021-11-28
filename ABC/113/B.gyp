n=int(input())
t,a=map(int,input().split())
H=[int(_) for _ in input().split()]
Tx=[]
for i in range(n):
    Tx.append([i+1,abs(a-t+H[i]*0.006)])
Tx.sort(key=lambda x:x[1])
print(Tx[0][0])

