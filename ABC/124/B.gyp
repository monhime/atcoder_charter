n=int(input())
H=[int(_) for _ in input().split()]
count=1
for i in range(1,n):
    if max(H[:i])<=H[i]:
        count+=1
print(count)