n=int(input())
a=[int(_) for _ in input().split()]
count=0
some=-1
for i in range(n-1):
    if a[i]==a[i+1]:
        count+=1
        a[i+1]=some
        some-=1
print(count)