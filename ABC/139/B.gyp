a,b=map(int,input().split())
tap=0
x=1
while 1:
    if x>=b:
        print(tap)
        break
    tap+=1
    x=x-1+a