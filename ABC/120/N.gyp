a,b,k=map(int,input().split())
count=k
for i in range(100):
    if a%(i+1)==0 and b%(i+1)==0:
        count+=1
        if count==K:
            print(i+1)
            break