min=0
N=[]
for i in range(5):
    n=int(input())
    N.append([n,(n-1)%10])
N.sort(key=lambda x:x[1])
time=0
for i in range(4):
    time+=(-N[i+1][0]//10)*-10
print(time+N[0][0])