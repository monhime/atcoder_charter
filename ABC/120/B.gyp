a,b,k=map(int,input().split())
N=[]
for i in range(100):
    if a%(i+1)==0 and b%(i+1)==0:
        N.append(i+1)
N.sort(reverse=True)
print(N[k-1])