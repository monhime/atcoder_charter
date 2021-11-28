n=int(input())
if n in [10,100,1000,10000,100000]:
    print(10)
else:
    sum=0
    for i in range(len(str(n))):
        sum+=n%10
        n=n//10
    print(sum)