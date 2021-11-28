n=int(input())
D=[int(_) for _ in input().split()]
sum=0
for i in range(n-1):
    for j in range(i+1,n):
        sum+=D[i]*D[j]
print(sum)