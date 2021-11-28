k,x=map(int,input().split())
s=""
for i in range(-k+1,k):
    s+=str(x+i)+' '
print(s)