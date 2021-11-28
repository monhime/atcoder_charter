n,l=map(int,input().split())
aji=[]
for i in range(n):
    aji.append(l+i)
apple=200
for i in range(n):
    if apple>abs(aji[i]):
        apple=abs(aji[i])
        apple_i=i
print(sum(aji)-aji[apple_i])
